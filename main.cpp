#include <vector>
#include <string>
#include <memory>
#include <iostream>


class Scene{
public:
	//TODO scene public methods

	Scene(std::shared_ptr<Primitive> aggregate,
			const std::vector<std::shared_ptr<Light>> &lights): lights(lights), aggregate(aggregate){
				//! worldBound = aggregate->WorldBound();  //! отличается от оригинала 24 стр
				for (const auto &light: lights){
					light->Preprocess(*this); //? some additional init. before rendering begins
				}
		  }
	
	const Bounds3f &WorldBound() const{
		return worldBound;
	}

	
	bool Intersect(const Ray & ray, SurfaceIntersaction *isect) const { 
		//! return aggregate->Intersect(ray, isect);  //! отличается от оригинала 24 стр
	}  //? returned a boolean value whether the ray intersected any of the primitives

	bool IntersectP(const Ray & ray, SurfaceIntersaction *isect) const{
		//! return aggregate->IntersectP(ray, isect);
	} //? checks for the existance of intersactions along the ray but does not return any information about intersactions (used for shadow rays)


	//TODO scene public data

	std::vector<std::shared_ptr<Light>> lights;  //? sources of lights in the Scene

private:
	//TODO scene private data

	std::shared_ptr<Primitive> aggregate;  //? stores all the Scene's Primitives(Primitive = Shape + Material)
	Bounds3f worldBound;
};


class Primitive{};

class Light{
public:
	void Preprocess(Scene & scene){}
};

class Options{};
class Bounds3f{};
class Ray{};
class SurfaceIntersaction{};

void pbrtInit(Options options);
void pbrtCleanup();
bool ParseFile(std::string filePath);
void Error(const char * errorMessage, const char * fileName);








void pbrtInit(Options options){}
void pbrtCleanup(){};
bool ParseFile(std::string filePath){}
void Error(const char * errorMessage, const char * fileName){
	printf(errorMessage ,fileName);
}



int main(int argc, char * argv[]){
	Options options;
	std::vector<std::string> filenames;
	
	//TODO Process comand-line arguments

	pbrtInit(options);



	// TODO Process scene description

	if (filenames.size() == 0){
		ParseFile("-");
	}
	else{
		for (const std::string &f: filenames){
			if (!ParseFile(f)){
				Error("Couldn't open the scene file", f.c_str());
			}
	}
	}

	pbrtCleanup();
	return 0;
}