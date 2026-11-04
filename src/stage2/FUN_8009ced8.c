/* FUN_8009ced8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ced8  body 0x8009ced8..0x8009d00f  size 312 B
 * body sha256 05b3c63fbe76617c1668a06ea3e1f59953139beb625539e85be1c0d74281140d
 * provider record sha256 eade0058f500cb1d473e22735f2e8ea89693a424a9224a2efb513006358d926b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009ced8(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_8013272b;
  if ((((&DAT_800e9184)[uVar2 * 0x16] != 0x7fff) && ((&DAT_800e9184)[uVar2 * 0x16] != -0x8000)) &&
     (*(short *)(&DAT_800e9186 + uVar2 * 0x2c) != 0x100)) {
    if ((DAT_80132728 & 2) == 0) {
      FUN_800274f8(DAT_8013272b | 0x200,0x100,7,1);
      DAT_8013272a = 2;
      DAT_80132728 = DAT_80132728 | 2;
    }
    else {
      iVar1 = FUN_8002767c();
      if (iVar1 != 0) {
        if ((DAT_80132728 & 4) == 0) {
          DAT_8013272a = (DAT_80132728 & 8) != 0;
          DAT_80132728 = DAT_80132728 & 0xf5;
        }
        else {
          DAT_8013272a = 3;
          DAT_80132740 = 0;
          DAT_80132728 = DAT_80132728 & 0xfd;
          FUN_8009e8d4(0,1);
        }
        FUN_800274e4(5,0);
      }
    }
  }
  return;
}
