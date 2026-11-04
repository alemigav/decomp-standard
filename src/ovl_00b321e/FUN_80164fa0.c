/* FUN_80164fa0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164fa0  body 0x80164fa0..0x8016513b  size 412 B
 * body sha256 e95072c36077ad49845d7949c513431fa1f33abfdcdd2c40ab4dc2a55071f9be
 * provider record sha256 771d5d79626dae8e93c20466f72b60cd4278ead4857e2fa8d3fec0031d9c692e
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164fa0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar2;
  uint uVar1;
  int iVar3;
  
  if (*(char *)(param_1 + 5) == *(char *)(param_1 + 0x2d6)) {
    *(undefined1 *)(param_1 + 0x2d7) = 1;
  }
  bVar2 = *(char *)(param_1 + 0x2cb) - 6;
  *(byte *)(param_1 + 0x2cb) = bVar2;
  if ((int)((uint)bVar2 << 0x18) < 0) {
    *(undefined1 *)(param_1 + 0x2cb) = 0;
  }
  if (((*(byte *)(param_1 + 0x2bd) & 1) == 0) || (*(char *)(param_1 + 0x2cb) != '\0')) {
    if (*(char *)(param_1 + 0x2ce) == '\0') {
      uVar1 = func_0x80033604(param_1);
      FUN_801663a4(param_1,3,uVar1 & 7);
      *(undefined1 *)(param_1 + 0x2ce) = 0xf;
    }
    FUN_801643d4(param_1,param_2,param_3);
  }
  else {
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    *(undefined1 *)(param_1 + 0x2d6) = *(undefined1 *)(param_1 + 5);
    if (*(char *)(param_1 + 0x2cb) == '\0') {
      uVar1 = 3;
      iVar3 = 0x468;
      do {
        uVar1 = uVar1 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar3 + 0x60) =
             *(undefined4 *)
              (&DAT_801667c8 + (((int)*(char *)(param_1 + 0x2cb) / 10) * 0x1000000 >> 0x16));
        iVar3 = iVar3 + 0x178;
      } while (uVar1 < 7);
    }
    if (*(char *)(param_1 + 0x2d7) == '\0') {
      func_0x80077d18(3,param_1);
    }
    *(undefined1 *)(param_1 + 0x2d7) = 0;
    if (*(char *)(param_1 + 700) == '\0') {
      *(undefined2 *)(param_1 + 6) = 0x200;
    }
    else if (*(char *)(param_1 + 0x2c5) == '\0') {
      *(undefined2 *)(param_1 + 6) = 0x100;
      FUN_801647ac(param_1,param_2,param_3);
    }
    else {
      *(undefined2 *)(param_1 + 6) = 0x300;
    }
  }
  return;
}
