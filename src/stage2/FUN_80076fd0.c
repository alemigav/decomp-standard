/* FUN_80076fd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80076fd0  body 0x80076fd0..0x8007742f  size 1120 B
 * body sha256 29d87b3bc9c26fb4319d326cec83e8f12da4564e3c6f534fba16283df4486397
 * provider record sha256 0e02f6605e73e3000aebb39a71b60460251c59f85a8e8d45d78e535f12b011b6
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80076fd0(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar2 = 0;
  if ((DAT_800e10ec & 0x2000) == 0) {
    if (-1 < (char)DAT_80119eee) {
      if (DAT_80119eec != '\0') {
        sVar3 = FUN_80079418((int)(char)DAT_80119eee,0);
        if (sVar3 != 0) {
          FUN_800790a4((int)(char)DAT_80119eee);
          while (sVar3 = FUN_80079418((int)(char)DAT_80119eee,0), sVar3 != 0) {
            FUN_8004cd88(1);
          }
        }
        DAT_80119eec = '\0';
      }
      FUN_80078b5c((int)(char)DAT_80119eee);
      DAT_80119eee = 0xff;
    }
    if (-1 < (char)DAT_80119ef6) {
      if (DAT_80119ef4 != '\0') {
        sVar3 = FUN_80079418((int)(char)DAT_80119ef6,0);
        if (sVar3 != 0) {
          FUN_800790a4((int)(char)DAT_80119ef6);
          while (sVar3 = FUN_80079418((int)(char)DAT_80119ef6,0), sVar3 != 0) {
            FUN_8004cd88(1);
          }
        }
        DAT_80119ef4 = '\0';
      }
      FUN_80078b5c((int)(char)DAT_80119ef6);
      DAT_80119ef6 = 0xff;
    }
    if (-1 < DAT_80119eae) {
      FUN_80075608(2,1);
      DAT_80119eae = -1;
    }
    if (-1 < DAT_80119eaf) {
      FUN_80075608(3,1);
      DAT_80119eaf = -1;
    }
    uVar2 = 0xffffffff;
    if (*(byte *)(DAT_80119ea0 + 1) != 0xff) {
      iVar4 = (*(byte *)(DAT_80119ea0 + 1) & 0x3f) * 2;
      uVar5 = (uint)(byte)(&DAT_80119d04)[iVar4];
      uVar6 = (uint)(byte)(&DAT_80119d05)[iVar4];
      if (uVar5 != 0xff) {
        iVar4 = uVar5 * 10;
        uVar2 = *(undefined4 *)(&DAT_80119a50 + iVar4);
        local_24 = CONCAT22(*(undefined2 *)(&DAT_80119a54 + iVar4),0xffff);
        local_20 = CONCAT22(0xffff,*(undefined2 *)(&DAT_80119a56 + iVar4));
        local_1c = CONCAT22(*(undefined2 *)(&DAT_80119a58 + iVar4),0xffff);
        DAT_80119eae = FUN_800752dc(*(undefined2 *)(&DAT_80119a50 + iVar4),2,1);
        DAT_80119eee = FUN_80075140(uVar2,local_24,local_20,local_1c);
        if (-1 < (int)((uint)DAT_80119eee << 0x18)) {
          sVar3 = FUN_80078af8(uVar5);
          FUN_80078c48((int)(char)DAT_80119eee,0,1,(int)sVar3);
          FUN_80079344((int)(char)DAT_80119eee,(int)DAT_80119ef0._0_2_,(int)DAT_80119ef0._0_2_);
        }
        DAT_80119eec = '\0';
      }
      if (uVar6 != 0xff) {
        iVar4 = uVar6 * 10;
        uVar2 = *(undefined4 *)(&DAT_80119a50 + iVar4);
        local_24 = CONCAT22(*(undefined2 *)(&DAT_80119a54 + iVar4),local_24._2_2_);
        uVar1 = *(undefined2 *)(&DAT_80119a56 + iVar4);
        local_1c = CONCAT22(*(undefined2 *)(&DAT_80119a58 + iVar4),local_1c._2_2_);
        DAT_80119eaf = FUN_800752dc(*(undefined2 *)(&DAT_80119a50 + iVar4),3,1);
        DAT_80119ef6 = FUN_80075140(uVar2,local_24,uVar1,local_1c);
        if (-1 < (int)((uint)DAT_80119ef6 << 0x18)) {
          sVar3 = FUN_80078af8(uVar6);
          FUN_80078c48((int)(char)DAT_80119ef6,0,1,(int)sVar3);
          FUN_80079344((int)(char)DAT_80119ef6,(int)DAT_80119ef8._0_2_,(int)DAT_80119ef8._0_2_);
        }
        DAT_80119ef4 = '\0';
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}
