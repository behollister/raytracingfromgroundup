class FBmTexture: public Texture {				public:			// constructors etc ...			virtual RGBColor 																					get_color(const ShadeRec& sr) const;		private:			LatticeNoise*		noise_ptr;		RGBColor 	  		color;							float		  		min_value, max_value;	// scaling factors};