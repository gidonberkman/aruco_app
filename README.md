# aruco_app

You can build  and run my application in a few simple steps on any linux machine that has docker installed:

Steps:

1)run the command on your limux machine:
    docker pull gidonberkmandocker22/gidons_images:opencv_ffmpeg_gcc_debian
2) clone this repository to  a new directory on your linux machine via this command:
      git clone https://github.com/gidonberkman/aruco_app.git
      
3) run the docker image and make the new directory from previous step accesible in the docker container via this command :
       docker run -it -v PATH_TO_YOUR_NEW_DIRECTORY:/shared_folder/ gidonberkmandocker22/gidons_images:opencv_ffmpeg_gcc_debian 
       
 4) once in the docker container run:
       cd /shared_folder/
 6) you'll see  that all the files from the git repo are here .now run the following cmake command which will generate the Makefile of the aruco_app :
        OpenCV_DIR=/cv/build/ cmake .
 7)now just run 'make' and the aruco application called aruco22 will be built.
 8) final step invoke the app via running ./aruco22  
 9) after the app has finished you'll see an output video file named output.avi in the current directory.
 
        
    