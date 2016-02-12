/// <reference path="typings/ue.d.ts">/>
(function (global) {
    "use strict"

    const proto = `
# The base learning rate, momentum and the weight decay of the network.
base_lr: 0.001
momentum: 0.9
weight_decay: 0.004
# The learning rate policy
lr_policy: "fixed"
# Display every 200 iterations
display: 200
# The maximum number of iterations
max_iter: 60000
# snapshot intermediate results
snapshot: 10000
snapshot_format: HDF5
snapshot_prefix: "test"
# solver mode: CPU or GPU
solver_mode: GPU

train_net_param {
    layer {
        name: 'memdata' type: 'MemoryData' top: 'target' top: 'dummy2'
        memory_data_param { batch_size: 4 channels: 4 width : 1 height : 1 }
    }
}`

    function Caffe() {
        let tray = new CoffeetrayProxy()
        return (command, payload) => {
            if (payload == undefined) {
                return tray.Send(command)
            } else if (typeof payload == 'number') {
                return tray.SendInteger(command,payload)
            } else if (typeof payload == 'string') {
                return tray.SendString(command, payload)
            } else if (payload instanceof ArrayBuffer) {
                memory.exec(payload, _ => tray.SendArray2(command))
                return true                  
            }
            return false
        }        
    }

    function main() {
        CoffeetrayProxy.Init("all")
        let tray = Caffe()
        let ab = new ArrayBuffer(32 * 4)
        let f = new Float32Array(ab)
        f[0] = 1
        f[16] = 2
        tray("solver_param set_string", proto) &&
        tray("solver create") &&
        tray("solver layer memdata reset",ab) &&
        tray("solver step",1)
        
        return _ => { }
    }

    try {
        module.exports = () => {
            let cleanup = null
            process.nextTick(() => {
                cleanup = main()
            });
            return () => cleanup()
        }
    }
    catch (e) {
        require('bootstrap')('app')
    }
})(this)
