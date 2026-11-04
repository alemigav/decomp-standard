/* FUN_801669bc
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x801669bc  body 0x801669bc..0x80166b6b  size 432 B
 * body sha256 8370b73ed41652b25f138d2f635ff98dc7ff361612e292953b0c4f399867b1a3
 * provider record sha256 64f02d383c7eb69445b119fa6f7788de6dd7502b00b4643b82d5648626d02859
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801669bc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar2;
  
  *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) | 0x82;
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    *(short *)(param_1 + 0x66) =
         *(short *)(param_1 + 0x66) + *(short *)(*(int *)(param_1 + 0x234) + 0x5a);
    *(undefined2 *)(*(int *)(param_1 + 0x234) + 0x5a) = 0;
    *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x1000;
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_80166ac8;
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    iVar1 = *(int *)(param_1 + 0x234);
    *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) & 0x7f;
    *(uint *)(iVar1 + 0x2f0) = *(uint *)(iVar1 + 0x2f0) & 0xfffff3ff;
    *(uint *)(iVar1 + 0x468) = *(uint *)(iVar1 + 0x468) & 0xfffff3ff;
    *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) & 0xefff;
  }
  func_0x80032b5c(param_1,0);
LAB_80166ac8:
  if ((*(byte *)(param_1 + 0x1e9) & 0xf) == 0) {
    bVar2 = func_0x80033604();
    DAT_80167fca = '\x03' - bVar2 % 6;
    bVar2 = func_0x80033604();
    DAT_80167fcb = '\x0f' - bVar2 % 0x1e;
  }
  return;
}
