# aruco_app
You can build  and run my application in a few simple steps on any linux machine that has docker installed.

Steps:

1)run this command on your linux machine:

    docker pull gidonberkmandocker22/gidons_images:opencv_ffmpeg_gcc_debian
    
2) clone this git repository to somehwere on your linux machine via this command:

      git clone https://github.com/gidonberkman/aruco_app.git
      
3) run the docker image and make the new cloned folder  from the previous step called 'aruco_app' accesible in the docker container via this command :
       docker run -it -v PATH_TO_YOUR_NEW_CLONED_FOLDER:/shared_folder/ gidonberkmandocker22/gidons_images:opencv_ffmpeg_gcc_debian 
       
       (PATH_TO_YOUR_NEW_CLONED_FOLDER should be the full path to aruco_app folder : /*/aruco_app/)
       
 4) once in the docker container run:
       cd /shared_folder/
 5) you'll see  that all the files from the git repo are here .Now run the following cmake command which will generate the Makefile of the aruco_app :
        OpenCV_DIR=/cv/build/ cmake .
        
 6) now just run 'make' and the aruco application called aruco22 will be built.
 7) final step invoke the app via running ./aruco22  
 8) after the app has finished running you'll see an output video file named output.avi in the current directory.
