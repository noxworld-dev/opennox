package server

import (
	"fmt"
	"strconv"

	"github.com/noxworld-dev/opennox-lib/spell"
)

func init() {
	RegisterObjectUseParse("ConsumeUse", parseUseConsume)
	RegisterObjectUseParse("ConsumeConfuseUse", parseUseConsume)
	RegisterObjectUseParse("CastUse", parseUseCast)
	RegisterObjectUseParse("EnchantUse", parseUseEnchant)
	RegisterObjectUseParse("PotionUse", parseUsePotion)
}

type ConsumeUseData struct {
	Value int32
}

type PotionUseData struct {
	Value int32
}

type CastUseData struct {
	Spell int32
}

type EnchantUseData struct {
	Enchant int32
	Dur     int32
}

func parseUseConsume(objt *ObjectType, args []string) error {
	use := (*ConsumeUseData)(objt.UseData)
	var s string
	if len(args) != 0 {
		s = args[0]
	}
	v, err := strconv.Atoi(s)
	if err != nil {
		return err
	}
	use.Value = int32(v)
	return nil
}

func parseUsePotion(objt *ObjectType, args []string) error {
	use := (*PotionUseData)(objt.UseData)
	var s string
	if len(args) != 0 {
		s = args[0]
	}
	v, err := strconv.Atoi(s)
	if err != nil {
		return err
	}
	use.Value = int32(v)
	return nil
}

func parseUseCast(objt *ObjectType, args []string) error {
	use := (*CastUseData)(objt.UseData)
	var s string
	if len(args) != 0 {
		s = args[0]
	}
	ind := spell.ParseID(s)
	if ind <= 0 {
		return fmt.Errorf("unsupported spell: %q", s)
	}
	use.Spell = int32(ind)
	return nil
}

func parseUseEnchant(objt *ObjectType, args []string) error {
	use := (*EnchantUseData)(objt.UseData)
	var s1, s2 string
	if len(args) >= 1 {
		s1 = args[0]
	}
	if len(args) >= 2 {
		s2 = args[1]
	}
	id, ok := ParseEnchant(s1)
	if !ok {
		return fmt.Errorf("unsupported enchant: %q", s1)
	}
	use.Enchant = int32(id)

	dur, err := strconv.Atoi(s2)
	if err != nil {
		return err
	}
	use.Dur = int32(dur)
	return nil
}
