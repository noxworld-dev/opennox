package things

type Draw interface {
	isDraw()
}

type BaseDraw struct {
	Img ImageRef `json:"base"`
}

func (BaseDraw) isDraw() {}

type StaticDraw struct {
	Img ImageRef `json:"static"`
}

func (StaticDraw) isDraw() {}

type WeaponDraw struct {
	Img ImageRef `json:"weapon"`
}

func (WeaponDraw) isDraw() {}

type ArmorDraw struct {
	Img ImageRef `json:"armor"`
}

func (ArmorDraw) isDraw() {}

type StaticRandomDraw struct {
	Imgs []ImageRef `json:"random"`
}

func (StaticRandomDraw) isDraw() {}

type DoorDraw struct {
	Imgs []ImageRef `json:"door"`
}

func (DoorDraw) isDraw() {}

type AnimateDraw struct {
	Anim Animation `json:"anim"`
}

func (AnimateDraw) isDraw() {}

type GlyphDraw struct {
	Anim Animation `json:"glyph"`
}

func (GlyphDraw) isDraw() {}

type WeaponAnimateDraw struct {
	Anim Animation `json:"weapon_anim"`
}

func (WeaponAnimateDraw) isDraw() {}

type ArmorAnimateDraw struct {
	Anim Animation `json:"armor_anim"`
}

func (ArmorAnimateDraw) isDraw() {}

type FlagDraw struct {
	Anim Animation `json:"flag"`
}

func (FlagDraw) isDraw() {}

type SphericalShieldDraw struct {
	Anim Animation `json:"spherical_shield"`
}

func (SphericalShieldDraw) isDraw() {}

type SummonEffectDraw struct {
	Anim Animation `json:"summon"`
}

func (SummonEffectDraw) isDraw() {}

type ConditionalAnimateDraw struct {
	Anims []Animation `json:"cond_anim"`
}

func (ConditionalAnimateDraw) isDraw() {}

type MonsterGeneratorDraw struct {
	Anims []Animation `json:"monster_gen"`
}

func (MonsterGeneratorDraw) isDraw() {}

func (f *Reader) readAnimation() (*Animation, error) {
	frames, err := f.readU8()
	if err != nil {
		return nil, err
	}
	ani := &Animation{Frames: make([]ImageRef, 0, frames)}
	v2, err := f.readU8()
	if err != nil {
		return nil, err
	}
	ani.Field = v2
	loop, err := f.readBytes8()
	if err != nil {
		return nil, err
	}
	if err := ani.Kind.UnmarshalText(loop); err != nil {
		return nil, err
	}
	for i := 0; i < int(frames); i++ {
		fr, err := f.readImageRef()
		if err != nil {
			return nil, err
		}
		ani.Frames = append(ani.Frames, *fr)
	}
	return ani, nil
}

func (f *Reader) skipAnimation() error {
	n, err := f.readU8()
	if err != nil {
		return err
	}
	if err := f.skip(1); err != nil {
		return err
	}
	if err := f.skipBytes8(); err != nil {
		return err
	}
	for i := 0; i < int(n); i++ {
		if err := f.skipImageRef(); err != nil {
			return err
		}
	}
	return err
}

func (f *Reader) readAnimations8() ([]Animation, error) {
	n, err := f.readU8()
	if err != nil {
		return nil, err
	}
	out := make([]Animation, 0, n)
	for i := 0; i < int(n); i++ {
		ani, err := f.readAnimation()
		if err != nil {
			return nil, err
		}
		out = append(out, *ani)
	}
	return out, nil
}

func (f *Reader) skipAnimations8() error {
	n, err := f.readU8()
	if err != nil {
		return err
	}
	for i := 0; i < int(n); i++ {
		if err := f.skipAnimation(); err != nil {
			return err
		}
	}
	return nil
}

func (f *Reader) skipThingDraw() error {
	dname, err := f.readString8()
	if err != nil {
		return err
	}
	_, err = f.readU64align()
	if err != nil {
		return err
	}
	switch dname {
	case "StaticDraw", "WeaponDraw", "ArmorDraw", "BaseDraw":
		if err := f.skipImageRef(); err != nil {
			return err
		}
	case "StaticRandomDraw", "DoorDraw":
		if err := f.skipImageRefs8(); err != nil {
			return err
		}
	case "AnimateDraw", "GlyphDraw", "WeaponAnimateDraw", "ArmorAnimateDraw",
		"FlagDraw", "SphericalShieldDraw", "SummonEffectDraw":
		if err := f.skipAnimation(); err != nil {
			return err
		}
	case "ConditionalAnimateDraw", "MonsterGeneratorDraw":
		if err := f.skipAnimations8(); err != nil {
			return err
		}
	case "AnimateStateDraw":
		if err := f.skipThingAnimStateDraw(); err != nil {
			return err
		}
	case "VectorAnimateDraw", "ReleasedSoulDraw":
		if err := f.skipThingAnimVectorDraw(); err != nil {
			return err
		}
	case "MonsterDraw", "MaidenDraw":
		if err := f.skipThingMonsterDraw(); err != nil {
			return err
		}
	case "PlayerDraw":
		if err := f.skipThingPlayerDraw(); err != nil {
			return err
		}
	case "SlaveDraw", "BoulderDraw", "ArrowDraw", "WeakArrowDraw", "HarpoonDraw":
		if err := f.skipImageRefs8(); err != nil {
			return err
		}
	}
	return nil
}

func (f *Reader) readThingDraw() (Draw, error) {
	dname, err := f.readString8()
	if err != nil {
		return nil, err
	}
	_, err = f.readU64align()
	if err != nil {
		return nil, err
	}
	switch dname {
	case "StaticDraw", "WeaponDraw", "ArmorDraw", "BaseDraw":
		img, err := f.readImageRef()
		if err != nil {
			return nil, err
		}
		switch dname {
		case "StaticDraw":
			return StaticDraw{Img: *img}, nil
		case "WeaponDraw":
			return WeaponDraw{Img: *img}, nil
		case "ArmorDraw":
			return ArmorDraw{Img: *img}, nil
		case "BaseDraw":
			return BaseDraw{Img: *img}, nil
		}
	case "StaticRandomDraw", "DoorDraw":
		imgs, err := f.readImageRefs8()
		if err != nil {
			return nil, err
		}
		switch dname {
		case "StaticRandomDraw":
			return StaticRandomDraw{Imgs: imgs}, nil
		case "DoorDraw":
			return DoorDraw{Imgs: imgs}, nil
		}
	case "AnimateDraw", "GlyphDraw", "WeaponAnimateDraw", "ArmorAnimateDraw",
		"FlagDraw", "SphericalShieldDraw", "SummonEffectDraw":
		anim, err := f.readAnimation()
		if err != nil {
			return nil, err
		}
		switch dname {
		case "AnimateDraw":
			return AnimateDraw{Anim: *anim}, nil
		case "GlyphDraw":
			return GlyphDraw{Anim: *anim}, nil
		case "WeaponAnimateDraw":
			return WeaponAnimateDraw{Anim: *anim}, nil
		case "ArmorAnimateDraw":
			return ArmorAnimateDraw{Anim: *anim}, nil
		case "FlagDraw":
			return FlagDraw{Anim: *anim}, nil
		case "SphericalShieldDraw":
			return SphericalShieldDraw{Anim: *anim}, nil
		case "SummonEffectDraw":
			return SummonEffectDraw{Anim: *anim}, nil
		}
	case "ConditionalAnimateDraw", "MonsterGeneratorDraw":
		anis, err := f.readAnimations8()
		if err != nil {
			return nil, err
		}
		switch dname {
		case "ConditionalAnimateDraw":
			return ConditionalAnimateDraw{Anims: anis}, nil
		case "MonsterGeneratorDraw":
			return MonsterGeneratorDraw{Anims: anis}, nil
		}
	case "AnimateStateDraw":
		if err := f.skipThingAnimStateDraw(); err != nil {
			return nil, err // FIXME
		}
	case "VectorAnimateDraw", "ReleasedSoulDraw":
		if err := f.skipThingAnimVectorDraw(); err != nil {
			return nil, err // FIXME
		}
	case "MonsterDraw", "MaidenDraw":
		if err := f.skipThingMonsterDraw(); err != nil {
			return nil, err // FIXME
		}
	case "PlayerDraw":
		if err := f.skipThingPlayerDraw(); err != nil {
			return nil, err // FIXME
		}
	case "SlaveDraw", "BoulderDraw", "ArrowDraw", "WeakArrowDraw", "HarpoonDraw":
		if err := f.skipImageRefs8(); err != nil {
			return nil, err // FIXME
		}
	}
	return nil, nil
}
