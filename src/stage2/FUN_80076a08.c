/* FUN_80076a08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80076a08  body 0x80076a08..0x80076b6f  size 360 B
 * body sha256 34ed3626dbf757113b6199ef97b69f9695cb4dcd30856628d5a85feef9ac433b
 * provider record sha256 ec4ae848dd6010f18de70057e89016114366195082608d4e4b58f45535270263
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80076a08(void)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  
  if ((DAT_800e10ec & 0x2000) == 0) {
    DAT_80119ea0 = &UNK_800e8b5c + DAT_800e8caa * 2 + (uint)(byte)(&DAT_80117118)[DAT_800e8ca8] * 2;
    if ((*DAT_80119ea0 & 0x3f) == (DAT_80119e9c & 0x3f)) {
      if ((DAT_80119ea0[1] & 0x3f) != (DAT_80119e9d & 0x3f)) {
        if ((DAT_80119eec == '\x01') && (sVar2 = FUN_80079418((int)DAT_80119eee,0), sVar2 != 0)) {
          FUN_80078ee4((int)DAT_80119eee,0x7f,0x5a);
          DAT_80119eec = '2';
        }
        if ((DAT_80119ef4 == '\x01') && (sVar2 = FUN_80079418((int)DAT_80119ef6,0), sVar2 != 0)) {
          FUN_80078ee4((int)DAT_80119ef6,0x7f,0x5a);
          DAT_80119ef4 = '2';
        }
      }
      iVar3 = 0x59;
      do {
        FUN_8004cd88(1);
        bVar1 = iVar3 != 0;
        iVar3 = iVar3 + -1;
      } while (bVar1);
    }
    else {
      FUN_80077430(0x5a,0x16);
    }
  }
  return;
}
