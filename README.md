# 执行命令
catkin init
catkin clean -y
catkin build -j20
source devel/setup.bash
roslaunch rio rio.launch visualize:=true

# 注意：
1、不能使用apt安装的gtsam，需要使用源码安装的gtsam（4.2.0）
2、gtsam_catkin这库会进行编译和安装作者自己自己fork的一个gtsam版本到这个工程里面而不是电脑环境里面。（作者的这个gtsam版本没有通过PR，所以只能克隆下来进行编译）
3、


