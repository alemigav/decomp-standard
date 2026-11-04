/* FUN_80164938
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164938  body 0x80164938..0x801649fb  size 196 B
 * body sha256 1f8e66a155ea8667524a08e0d90a87cc7522b7113cb9dddbeec85e99b8cc76d2
 * provider record sha256 1599a5f553d6891fc2635bc387d016408f72b457eea03c466a6bb8cdad04ea78
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164938(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x2c8) = 1;
  iVar1 = FUN_80163060();
  if (iVar1 < 0) {
    *(undefined2 *)(param_1 + 6) = 0x200;
    *(undefined4 *)(param_1 + 0x1e8) = 0x15000f00;
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
  if ((*(uint *)(param_1 + 0x1ac) & 1) != 0) {
    *(undefined2 *)(param_1 + 6) = 0x300;
    *(undefined4 *)(param_1 + 0x1e8) = 0x16000f00;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x270) = 1;
    *(short *)(param_1 + 0x1e0) = -(*(short *)(param_1 + 0x1e0) >> 1);
  }
  return;
}
