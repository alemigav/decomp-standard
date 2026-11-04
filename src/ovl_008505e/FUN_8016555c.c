/* FUN_8016555c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016555c  body 0x8016555c..0x8016563b  size 224 B
 * body sha256 e8296d8f78298c9808d20b136e6ad29073af9c1c14717cc3a488fffa2c35c8db
 * provider record sha256 27135f58cc664961ca8dfc78088226191e2f5e3bfab152e3b2ffe63d617e025a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016555c(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar2;
  int iVar1;
  
  if (*(char *)(param_1 + 700) == '\0') {
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 500));
    FUN_8016655c(param_1,10,0);
    if (*(char *)(param_1 + 7) == '\0') {
      *(undefined1 *)(param_1 + 7) = 1;
      uVar2 = func_0x80033604(param_1);
      *(ushort *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + ((uVar2 & 0xff) - 0x80);
    }
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,(int)*(short *)(param_1 + 0x1f6));
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x300;
    *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) & 0xc0 | 2;
    *(undefined1 *)(param_1 + 0x206) = 0;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x1ea) * 0x100 + 0x12000000;
  }
  return;
}
