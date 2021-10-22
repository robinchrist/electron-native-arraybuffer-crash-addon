import { join } from 'path';
const isElectron = !!(process.versions as any)['electron'];

// Build a path, recursive to the current directory.
// Consists of platform, arch, runtime, runtimeABI, 'addon.node';
// e.g. ./windows/x64/electron/64/addon.node;
const path = './' + join(process.platform, process.arch, isElectron ? 'electron' : 'node', process.versions.modules, 'addon.node');


export type NativeModule = {
  calculateSync: (xRot: number, yRot: number, zRot: number) => any;
}

export const NATIVE = require(path) as NativeModule;
