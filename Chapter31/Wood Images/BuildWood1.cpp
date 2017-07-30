// 	Copyright (C) Kevin Suffern 2000-2008.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// This builds the scene for the figure Wood1.jpg
// The wood parameters are similar to the oak wood texture specified 
// in Apadoca and Gritz (2000), p 308.
// This figure, and the other three wood images are based on Figure 12.9 in
// Apadoca and Gritz.

// This is a cross cut view showing the rings.

void 												
World::build(void) {
	int num_samples = 9;
	
	vp.set_hres(600);
	vp.set_vres(600);
	vp.set_samples(num_samples);
	
	tracer_ptr = new RayCast(this);
	background_color = black;
			
	Ambient* ambient_ptr = new Ambient;
	ambient_ptr->scale_radiance(1.0);   
	set_ambient_light(ambient_ptr);
		

	Pinhole* pinhole_ptr = new Pinhole;
	pinhole_ptr->set_eye(0, 100, 0);  
	pinhole_ptr->set_lookat(0.0); 
	pinhole_ptr->set_view_distance(15000.0);  
	pinhole_ptr->compute_uvw(); 
	set_camera(pinhole_ptr);
	
		
	Directional* light_ptr = new Directional;
	light_ptr->set_direction(0, 1, 0); 
	light_ptr->scale_radiance(4.0);  
	add_light(light_ptr);
	
	
	// wood texture
	
	// This Wood constructor just specifies the light and dark colors.
	// The other parameters are defaults.
	
	RGBColor light_color(0.5, 0.2, 0.065);
	RGBColor dark_color(0.05);

	Wood* wood_ptr = new Wood(light_color, dark_color);
	wood_ptr->set_grainy(1.0);
	wood_ptr->set_ringy(1.0);
	
	TInstance* transformed_wood_ptr = new TInstance(wood_ptr);
	transformed_wood_ptr->scale(0.4);
	
	
	// material
	
	SV_Matte* sv_matte_ptr = new SV_Matte;		
	sv_matte_ptr->set_ka(0.75);
	sv_matte_ptr->set_kd(0.85);
	sv_matte_ptr->set_cd(transformed_wood_ptr);
	
	
	// box
	
	Point3D p0(-2.0, -2.0, -2.0);
	Point3D p1(2.0, 2.0, 2.0);
	
	Box* box_ptr = new Box(p0, p1); 
	box_ptr->set_material(sv_matte_ptr);
	add_object(box_ptr);	
}


