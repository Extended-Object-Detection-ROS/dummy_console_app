/*
 * Simple example of Extended Object Detection main functionallity
 */

#include <stdio.h>
#include "ObjectBase.h"

#include <string>
#include <vector>

int main(int argc, char **argv)
{
    printf("Simple Extended Object Detection Test!\n");
    
    // read image
    cv::Mat frame = cv::imread("../../images/two-cups-on-wooden-table_1373-290.jpg");      
            
    // draw results
    cv::Mat image2draw = frame.clone();    
    redCup.draw(image2draw, cv::Scalar(0,255,0));
    cv::imshow("result", image2draw);
    int k = 0;
    while(k != 27)
        k = cv::waitKey(1);
    
    return 0;
}
