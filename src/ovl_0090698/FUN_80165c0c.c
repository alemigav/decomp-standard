/* FUN_80165c0c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165c0c  body 0x80165c0c..0x80165cbf  size 180 B
 * body sha256 4b5999fda4b1d0984d7a86ef7fe8bd276890045a43a4a4b78b5c6bed7368d1a9
 * provider record sha256 394d79912ee2dc8f5c3d1231134c2cb53cb181d8ea3fc81caa8fa50108dd4839
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c0c(int param_1)

{
  *(undefined2 *)(param_1 + 500) = 0x800;
  *(undefined1 *)(param_1 + 6) = 1;
  *(undefined4 *)(param_1 + 0x1e8) = 0x1090000;
  func_0x80089d54();
  *(undefined1 *)(param_1 + 0x2bf) = 1;
  *(undefined2 *)(param_1 + 0x2b6) = 0;
  *(undefined2 *)(param_1 + 0x1e0) = 0x1e0;
  *(undefined2 *)(param_1 + 0x1e2) = 0;
  *(undefined2 *)(param_1 + 0x1e4) = 0;
  if ((*(byte *)(param_1 + 0x2cc) & 1) == 0) {
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    *(short *)(param_1 + 500) = -*(short *)(param_1 + 100);
  }
  else {
    *(undefined2 *)(param_1 + 500) = 0;
    *(ushort *)(param_1 + 0x1f6) =
         (ushort)*(byte *)(param_1 + 0x2cc) * 0x400 - *(short *)(param_1 + 0x66);
  }
  if (*(char *)(param_1 + 0x2d8) != '\x01') {
    FUN_8016703c(param_1,0,0);
  }
  return;
}
