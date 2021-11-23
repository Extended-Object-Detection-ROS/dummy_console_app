# dummy_console_app
Simplest console application for basic testing of system.

## Install 
(Testetd on Linux Kubuntu 20.04 LTS)
It is supposed that you already have OpenCV 4.2.0 installed
### 1. Download repo
```
git clone --recurse-submodules https://github.com/Extended-Object-Detection-ROS/dummy_console_app
```

### 2. (Optional) install igraph library
If you want to use Complex Object Detection
```
mkdir tmp
cd tmp
curl -O https://igraph.org/nightly/get/c/igraph-0.7.1.tar.gz
tar -xzf igraph-0.7.1.tar.gz
rm igraph-0.7.1.tar.gz

sudo mv igraph-0.7.1 /usr/local/src/
cd /usr/local/src/igraph-0.7.1
./configure
make
make check
sudo make install
```
Then in file dummy_console_app/CMakeLists.txt change line 8 at
```
set(igraph ON)
```
### 3. Build application
```
cd dummy_console_app
mkdir build
cd build
cmake ..
make
```

## Run
```
./dummy_console_app <path to object base XML file> <path to image to dertect> [optional: names of objects ti detect]
```
If no object names to detect provided then all objects in base will be detected.


## Examples
You can take ready object base with provided examples from https://github.com/Extended-Object-Detection-ROS/opencv_blog_olympics_examples  
And perform biker detection (with igraph installed) with command like:
```
./dummy_console_app /home/anton/Pictures/opencv_blog_olympics_examples/objectbase/ObjectBase.xml /home/anton/Pictures/opencv_blog_olympics_examples/images/judgment_day_alone_75.jpg Biker
```

![filled gui](doc/Biker_detected.png)


