/* FUN_80076c84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80076c84  body 0x80076c84..0x80076fcf  size 844 B
 * body sha256 2a4c9018544ee1ea24287afcb0ac19e7487802edc53149668301ee71798a84be
 * provider record sha256 9b11918506dd14ebb258fc943c9441a9a8ab1529167cd03ad4392f5386986031
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80076c84(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short sVar5;
  int iVar6;
  undefined4 local_20;
  
  uVar4 = 0;
  if ((DAT_800e10ec & 0x2000) == 0) {
    DAT_80119e78 = 0;
    if (-1 < (char)DAT_80119ee6) {
      if (DAT_80119ee4 != '\0') {
        sVar5 = FUN_80079418((int)(char)DAT_80119ee6,0);
        if (sVar5 != 0) {
          FUN_800790a4((int)(char)DAT_80119ee6);
        }
        DAT_80119ee4 = '\0';
      }
      FUN_80078b5c((int)(char)DAT_80119ee6);
      DAT_80119ee6 = 0xff;
    }
    if (-1 < DAT_80119ead) {
      FUN_80075608(1,1);
      DAT_80119ead = -1;
    }
    if (*DAT_80119ea0 == 0xff) {
      uVar4 = 0xffffffff;
    }
    else {
      if (-1 < DAT_80119eee) {
        if (DAT_80119eec != '\0') {
          sVar5 = FUN_80079418((int)DAT_80119eee,0);
          if (sVar5 != 0) {
            FUN_800790a4((int)DAT_80119eee);
          }
          DAT_80119eec = '\0';
        }
        FUN_80078b5c((int)DAT_80119eee);
        DAT_80119eee = -1;
      }
      if (-1 < DAT_80119ef6) {
        if (DAT_80119ef4 != '\0') {
          sVar5 = FUN_80079418((int)DAT_80119ef6,0);
          if (sVar5 != 0) {
            FUN_800790a4((int)DAT_80119ef6);
          }
          DAT_80119ef4 = '\0';
        }
        FUN_80078b5c((int)DAT_80119ef6);
        DAT_80119ef6 = -1;
      }
      if (-1 < DAT_80119eae) {
        FUN_80075608(2,1);
        DAT_80119eae = -1;
      }
      if (-1 < DAT_80119eaf) {
        FUN_80075608(3,1);
        DAT_80119eaf = -1;
      }
      bVar1 = *DAT_80119ea0;
      iVar6 = (bVar1 & 0x3f) * 0xe;
      uVar4 = *(undefined4 *)(&DAT_80119794 + iVar6);
      uVar2 = *(undefined4 *)(&DAT_80119798 + iVar6);
      local_20 = CONCAT22(0xffff,*(undefined2 *)(&DAT_8011979c + iVar6));
      uVar3 = *(undefined4 *)(&DAT_8011979e + iVar6);
      DAT_80119ead = FUN_800752dc(*(undefined2 *)(&DAT_80119794 + iVar6),1,1);
      DAT_80119ee6 = FUN_80075140(uVar4,uVar2,local_20,uVar3);
      if (-1 < (int)((uint)DAT_80119ee6 << 0x18)) {
        sVar5 = FUN_80078ab8(bVar1 & 0x3f);
        FUN_80078c48((int)(char)DAT_80119ee6,0,1,(int)sVar5);
        FUN_80079344((int)(char)DAT_80119ee6,(int)DAT_80119ee8,(int)DAT_80119ee8);
      }
      DAT_80119ee4 = '\0';
      uVar4 = 0;
    }
  }
  return uVar4;
}
