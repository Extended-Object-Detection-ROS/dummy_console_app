/*
 * Simple example of Extended Object Detection testing
 */

#include <stdio.h>
#include "ObjectBase.h"

#include <string>
#include <vector>

bool check_name(const std::vector<std::string> &names, const std::string &name){
    if( names.size() == 0)
        return true;
    
    if(std::find(names.begin(), names.end(), name) != names.end()) {
        return true;        
    }
    return false;    
}

int main(int argc, char **argv)
{
    if( argc < 3 ){
        printf("Wrong input!\n Usage: ./dummy_console_app <path to XML object base file> <path to image to detect on> [optional: name of objects to detect]\n Example: ./dummy_console_app MyObjectBase.xml image.png MyObject1 MyObject2\n");
        return -1;
    }    
    printf("Dummy console application started\n");
    
    // read object base
    eod::ObjectBase object_base;    
    if( !object_base.loadFromXML(argv[1]) ){
        printf("Error! Can;t read object base on path %s.\n", argv[1]);
        return -2;
    }    
    
    // read image
    cv::Mat frame = cv::imread(argv[2]);      
    if( frame.empty() ){
        printf("Error! Can't read image on path %s.\n", argv[2]);
        return -3;
    }
    
    // get names of objects to detect
    std::vector<std::string> objects2detect;
    for( int i = 3 ; i < argc ; i++ ){
        objects2detect.push_back(argv[i]);
    }
            
    // detect and draw
    cv::Mat image2draw = frame.clone();    
    for( auto so : object_base.simple_objects ){                        
        if( check_name(objects2detect, so->name)){        
            so->Identify(frame, cv::Mat(), 0);
            so->draw(image2draw, cv::Scalar(0,255,0));
        }
    }
#ifdef USE_IGRAPH    
    for( auto co : object_base.complex_objects_graph ){                        
        if( check_name(objects2detect, co->name)){        
            co->Identify(frame, cv::Mat(), 0);
            co->drawAll(image2draw, cv::Scalar(255,255,0), 2);
        }
    }
#endif    
        
    printf("Detection has been performed! Press ESC to exit.\n");
    
    cv::imshow("result", image2draw);
    int k = 0;
    while(k != 27)
        k = cv::waitKey(1);
    
    return 0;
}
