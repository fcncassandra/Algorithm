# 1 原理

# 2 使用

按[mmdetection](https://mmdetection.readthedocs.io/zh_CN/v2.18.1/get_started.html#id2)要求安装环境

```
conda create -n lyf-open-mmlab python=3.7 -y
conda activate lyf-open-mmlab
```

TODO：查看cuda版本，根据版本安装，我的版本是CUDA Version 10.1.243，但是nvidia-smi的CUDA Version: 10.2，到底用什么呢？

```
cat /usr/local/cuda/version.txt 
```

这台电脑原来装了很多cuda版本的驱动安装包，但是现在的cuda是10.2

```
(lyf-open-mmlab) [root@automlgpu4 local]# pwd
/usr/local
(lyf-open-mmlab) [root@automlgpu4 local]# ls
apache-maven-3.6.3  doc        hadoop-2.7.1.tar.gz  kube-flow  scala-2.11.12              tomcat
bin                 etc        hbase                lib        share                      venv
cuda                games      hive                 lib64      spark-2.4.7-bin-hadoop2.7  VERSION
cuda-10.1           gcc-9.2.0  include              libexec    spark-3.0.1-bin-hadoop3.2  zookeeper
cuda-10.2           go         kf                   sbin       src
```



安装对应cuda版本的pytorch包

```
conda install pytorch cudatoolkit=10.1 torchvision -c pytorch
```

没用推荐的mim来安装因为要搭梯子，就直接pip了

```
pip install mmcv-full
pip install mmdet
```

然后为了测试代码包需要用到工程的demo，所以需要拉一下git，如果网不好可以自己下下来传上去解压

```
git clone https://github.com/open-mmlab/mmdetection.git
cd mmdetection
```

我在mmdetection同路径创建了文件夹test，里面创建了checkpoints文件夹，也编辑了demo.py文件

```python
from mmdet.apis import init_detector, inference_detector
 
config_file = 'mmdetection/configs/faster_rcnn/faster_rcnn_r50_fpn_1x_coco.py'
# 从 model zoo 下载 checkpoint 并放在 `checkpoints/` 文件下
# 网址为: http://download.openmmlab.com/mmdetection/v2.0/faster_rcnn/faster_rcnn_r50_fpn_1x_coco/faster_rcnn_r50_fpn_1x_coco_20200130-047c8118.pth
checkpoint_file = 'checkpoints/faster_rcnn_r50_fpn_1x_coco_20200130-047c8118.pth'
device = 'cuda:0'
# 初始化检测器
model = init_detector(config_file, checkpoint_file, device=device)
# 推理演示图像
inference_detector(model, 'mmdetection/demo/demo.jpg')
```

然后开始python demo.py执行，结果报错

```
(lyf-open-mmlab) [root@automlgpu4 test]# python demo.py
No CUDA runtime is found, using CUDA_HOME='/usr/local/cuda'
Traceback (most recent call last):
  File "demo.py", line 1, in <module>
    from mmdet.apis import init_detector, inference_detector
  File "/data/conda/envs/lyf-open-mmlab/lib/python3.7/site-packages/mmdet/apis/__init__.py", line 2, in <module>
    from .inference import (async_inference_detector, inference_detector,
  File "/data/conda/envs/lyf-open-mmlab/lib/python3.7/site-packages/mmdet/apis/inference.py", line 7, in <module>
    from mmcv.ops import RoIPool
  File "/data/conda/envs/lyf-open-mmlab/lib/python3.7/site-packages/mmcv/ops/__init__.py", line 2, in <module>
    from .assign_score_withk import assign_score_withk
  File "/data/conda/envs/lyf-open-mmlab/lib/python3.7/site-packages/mmcv/ops/assign_score_withk.py", line 6, in <module>
    '_ext', ['assign_score_withk_forward', 'assign_score_withk_backward'])
  File "/data/conda/envs/lyf-open-mmlab/lib/python3.7/site-packages/mmcv/utils/ext_loader.py", line 13, in load_ext
    ext = importlib.import_module('mmcv.' + name)
  File "/data/conda/envs/lyf-open-mmlab/lib/python3.7/importlib/__init__.py", line 127, in import_module
    return _bootstrap._gcd_import(name[level:], package, level)
ImportError: /data/conda/envs/lyf-open-mmlab/lib/python3.7/site-packages/mmcv/_ext.cpython-37m-x86_64-linux-gnu.so: undefined symbol: _Z27points_in_boxes_cpu_forwardN2at6TensorES0_S0_
```

