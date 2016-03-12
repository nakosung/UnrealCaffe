# UnrealCaffe: Caffe test on UnrealEngine4 

- PoC for coupling between UnrealEngine and Caffe.

1. Build coffeetray from github.com/nakosung/caffe
1. Install Unreal.js
1. `mklink /d /j Plugins %UNREALJS%\Plugins`
1. Open and play

*CAUTION* coffeetray directory is hard-coded and necessary binaries should be copied manually.

```
LogCaffe: I0213 01:45:50.000000  6156 coffeetray.cpp:221] Using GPUs 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\common.cpp:32] System entropy source not available, using fallback algorithm to generate seed instead.
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:48] Initializing solver from parameters: 
base_lr: 0.001
display: 200
max_iter: 60000
lr_policy: "fixed"
momentum: 0.9
weight_decay: 0.004
snapshot: 10000
snapshot_prefix: "test"
solver_mode: GPU
train_net_param {
  layer {
    name: "memdata"
    type: "MemoryData"
    top: "target"
    top: "dummy2"
    memory_data_param {
      batch_size: 4
      channels: 4
      height: 1
      width: 1
    }
  }
}
snapshot_format: HDF5
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:77] Creating training net specified in train_net_param.
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:59] Initializing net from parameters: 
state {
  phase: TRAIN
}
layer {
  name: "memdata"
  type: "MemoryData"
  top: "target"
  top: "dummy2"
  memory_data_param {
    batch_size: 4
    channels: 4
    height: 1
    width: 1
  }
}
LogCaffe: I0213 01:45:51.000000  6156 C:\app\caffe\include\caffe/layer_factory.hpp:78] Creating layer memdata
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:116] Creating Layer memdata
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:421] memdata -> target
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:421] memdata -> dummy2
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:160] Setting up memdata
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:167] Top shape: 4 4 1 1 (16)
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:167] Top shape: 4 (4)
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:175] Memory required for data: 80
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:238] memdata does not need backward computation.
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:280] This network produces output dummy2
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:280] This network produces output target
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\net.cpp:293] Network initialization done.
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:60] Solver scaffolding done.
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:237] Iteration 0, loss = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #0: dummy2 = 2
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #1: dummy2 = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #2: dummy2 = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #3: dummy2 = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #4: target = 1
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #5: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #6: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #7: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #8: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #9: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #10: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #11: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #12: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #13: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #14: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #15: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #16: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #17: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #18: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solver.cpp:253]     Train net output #19: target = 0
LogCaffe: I0213 01:45:51.000000  6156 ..\src\caffe\solvers\sgd_solver.cpp:106] Iteration 0, lr = 0.001
```
