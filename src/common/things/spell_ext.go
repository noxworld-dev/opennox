package things

type MissilesSpellConf struct {
	MissilesSpell `yaml:",inline"`
	Levels        []MissilesSpell `json:"levels,omitempty" yaml:"levels,omitempty"`
}

func (opts *MissilesSpellConf) Level(lvl int) MissilesSpell {
	if opts == nil {
		var out MissilesSpell
		out.SetDefaults()
		return out
	}
	out := opts.MissilesSpell
	out.SetDefaults()
	if len(opts.Levels) == 0 {
		return out
	}
	lvl--
	if lvl < 0 {
		return out
	} else if n := len(opts.Levels); lvl >= n {
		out.Merge(&opts.Levels[n-1])
	} else {
		out.Merge(&opts.Levels[lvl])
	}
	return out
}

type MissilesSpell struct {
	Count       int     `json:"count,omitempty" yaml:"count,omitempty"`
	Spread      uint16  `json:"spread,omitempty" yaml:"spread,omitempty"`
	Projectile  string  `json:"projectile,omitempty" yaml:"projectile,omitempty"`
	VelMult     float32 `json:"vel_mult,omitempty" yaml:"vel_mult,omitempty"`
	Offset      float32 `json:"offset,omitempty" yaml:"offset,omitempty"`
	SpeedRndMin float64 `json:"speed_rnd_min,omitempty" yaml:"speed_rnd_min,omitempty"`
	SpeedRndMax float64 `json:"speed_rnd_max,omitempty" yaml:"speed_rnd_max,omitempty"`
	SearchDist  float32 `json:"search_dist,omitempty" yaml:"search_dist,omitempty"`
}

func (opts *MissilesSpell) SetDefaults() {
	if opts.Spread == 0 {
		opts.Spread = 16
	}
	if opts.Projectile == "" {
		opts.Projectile = "MagicMissile"
	}
	if opts.Offset == 0 {
		opts.Offset = 4.0
	}
	if opts.VelMult == 0 {
		opts.VelMult = 0.1
	}
	if opts.SpeedRndMin == 0 {
		opts.SpeedRndMin = 0.80000001
	}
	if opts.SpeedRndMax == 0 {
		opts.SpeedRndMax = 1.2
	}
	if opts.SearchDist == 0 {
		opts.SearchDist = 600.0
	}
}

func (opts *MissilesSpell) Merge(opts2 *MissilesSpell) {
	if opts2.Spread != 0 {
		opts.Spread = opts2.Spread
	}
	if opts2.Projectile != "" {
		opts.Projectile = opts2.Projectile
	}
	if opts2.Offset != 0 {
		opts.Offset = opts2.Offset
	}
	if opts2.VelMult != 0 {
		opts.VelMult = opts2.VelMult
	}
	if opts2.SpeedRndMin != 0 {
		opts.SpeedRndMin = opts2.SpeedRndMin
	}
	if opts2.SpeedRndMax != 0 {
		opts.SpeedRndMax = opts2.SpeedRndMax
	}
	if opts2.SearchDist != 0 {
		opts.SearchDist = opts2.SearchDist
	}
}
