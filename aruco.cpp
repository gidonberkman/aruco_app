#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace cv;
using namespace std;
using namespace aruco;

int main()
{
    Mat src;
    // use file  as video source
    VideoCapture cap("./aruco.mp4");
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open file\n";
        return -1;
    }
    // get one frame from file  to know frame size and type
    cap >> src;
    // check if we succeeded
    if (src.empty()) {
        cerr << "ERROR! empty frame grabbed\n";
        return -1;
    }
    
    //initialize video writer
    VideoWriter writer;
    int codec = VideoWriter::fourcc('X', 'V', 'I', 'D');  
    double fps = 25.0;                          
    string filename = "./intermediate.avi";             
    writer.open(filename, codec, fps, src.size());
    // check if we succeeded
    if (!writer.isOpened()) {
        cerr << "failed to open the output video file for writing\n";
        return -1;
    }
    
    vector<int> ids;
    vector<vector<Point2f>> corners;
    Ptr<Dictionary> dictionary = getPredefinedDictionary(DICT_6X6_250);
    
    //get all  frames from video file one by one. check each for aruco markers in it and if marker(s) were found draw on frame the marker(s) .
    //write each frame (modified or not) to the  intermediate output file -intermediate.avi
    for (;;)
    {
        // check if we succeeded to get frame 
        if (!cap.read(src)) {
            break;
        }

        detectMarkers(src, dictionary, corners, ids);
        if (ids.size() > 0)
            drawDetectedMarkers(src, corners, ids);
        writer.write(src);
        
        double r = ((double) rand() / (RAND_MAX));
        usleep(r * 60 * 1000); // Sleep for a random time in range of 0-60 ms

    }
    //convert the intermediate.avi file to a lower resolution video file which will be our output file - output.avi and delete the intermediate.avi file  
    system("ffmpeg -i ./intermediate.avi  -vcodec h264  -crf 25 -y ./output.avi; rm ./intermediate.avi");
    return 0;
}