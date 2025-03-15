catkin init

catkin build -j10
catkin_make -j20

source devel/setup.bash


roslaunch rio rio.launch visualize:=true

注意：
1、这个框架很离谱，不知道为什么必须把apt安装的ros-noetic-gtsam给卸载了才能正常运行。
（现在是使用了自己本地apt安装的gtsam，编译成功了，但是运行就会报错；我把cmakelists中的gtsam_catkin依赖删掉了，把common、optimization的cpp和h文件中的一些函数和shared_ptr给改了，也改了一个包含的头文件）