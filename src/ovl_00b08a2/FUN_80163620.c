/* FUN_80163620
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80163620  body 0x80163620..0x801636a3  size 132 B
 * body sha256 4f70ab28a1c8631a4d6b83a8f3f7e296dacbdec2c35db2182abf1a9a4f4c10a3
 * provider record sha256 7dec5057d7335f6cb8c189b232bdacef9ca1d1442f6bfde5576986ca638c153d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163620(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x234);
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
    *(undefined1 *)(param_1 + 6) = 1;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80089d54(param_1,param_2,param_3,0x80);
  uVar1 = *(short *)(iVar2 + 0x124) - 0x40;
  *(ushort *)(iVar2 + 0x124) = uVar1;
  if ((int)((uint)uVar1 << 0x10) < 0) {
    *(undefined2 *)(iVar2 + 0x124) = 0;
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  return;
}
