/* FUN_8007c724
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c724  body 0x8007c724..0x8007c9b3  size 656 B
 * body sha256 581ef9b4cef3f7a6b0584b7d84c6a3b2ad073824297365fe90ced215fd95149c
 * provider record sha256 cc5b79206384c986b17d1880ce6b1604f8ae04a72fba676022be4d29b426439a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c724(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 0x1ed) = 0;
    iVar4 = (int)*(short *)(param_1 + 0x1fe);
    iVar5 = (int)*(short *)(param_1 + 0x1f2) << 0xc;
    iVar6 = iVar5 / iVar4;
    if (iVar4 == 0) {
      trap(0x1c00);
    }
    if ((iVar4 == -1) && (iVar5 == -0x80000000)) {
      trap(0x1800);
    }
    if ((DAT_800e900f & 1) != 0) {
      *(undefined1 *)(param_1 + 0x1ed) = 1;
    }
    if (iVar6 < 2000) {
      *(undefined1 *)(param_1 + 0x1ed) = 1;
    }
    if (iVar6 < 800) {
      *(undefined1 *)(param_1 + 0x1ed) = 2;
    }
  }
  if ((DAT_8011b54c != 0) && ((DAT_800e112a & 1) != 0)) {
    (*(code *)(&PTR_FUN_8011b250)
              [*(byte *)((int)&PTR_LAB_8011b210 + (uint)*(byte *)(DAT_8011b54c + 8))])
              (param_1,*(undefined2 *)(param_1 + 0x1aa));
  }
  iVar4 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),
                       0x400);
  if ((*(ushort *)(param_1 + 0x2b8) & 0x8000) == 0) {
    if (((*(ushort *)(param_1 + 0x1aa) & 0xf) == 10) && (500 < *(ushort *)(param_1 + 0x2ba))) {
      uVar2 = 0x1010000;
      if (iVar4 != 0) {
        uVar2 = 0x10c0000;
      }
    }
    else if (*(ushort *)(param_1 + 0x2ba) < 0xbb9) {
      if (*(ushort *)(param_1 + 0x2ba) < 0x1771) {
        bVar1 = false;
        if (((*(uint *)(param_1 + 0x28c) < 4000) && (DAT_800e1134._1_1_ == '\x02')) &&
           (cVar3 = FUN_80033160(param_1,&DAT_800e1130), cVar3 == '\0')) {
          iVar4 = FUN_80032e74(param_1,DAT_800e1158,DAT_800e1160,0x200);
          bVar1 = iVar4 == 0;
        }
        uVar2 = 0x1030000;
        if (!bVar1) {
          bVar1 = false;
          if (((*(uint *)(param_1 + 0x28c) < 1000) && (DAT_800e1134._1_1_ == '\x01')) &&
             (cVar3 = FUN_80033160(param_1,&DAT_800e1130), cVar3 == '\0')) {
            iVar4 = FUN_80032e74(param_1,DAT_800e1158,DAT_800e1160,0x200);
            bVar1 = iVar4 == 0;
          }
          uVar2 = 0x1030000;
          if (!bVar1) {
            return;
          }
        }
      }
      else {
        uVar2 = 0x1020000;
        if (iVar4 != 0) {
          uVar2 = 0x10d0000;
        }
      }
    }
    else {
      uVar2 = 0x1010000;
      if (iVar4 != 0) {
        uVar2 = 0x10c0000;
      }
    }
  }
  else {
    uVar2 = 0x1010000;
    if (iVar4 != 0) {
      uVar2 = 0x10c0000;
    }
  }
  *(undefined4 *)(param_1 + 4) = uVar2;
  return;
}
