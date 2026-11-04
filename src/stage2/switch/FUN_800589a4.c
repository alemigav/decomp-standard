/* FUN_800589a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800589a4  body 0x800589a4..0x80058b5b  size 440 B
 * body sha256 b89e0a91a36b85033cc5ea67b6544e418ad49088722dadf96fc9d1f3a280d81d
 * provider record sha256 91c23764a944b080116365267b1b4ca6260c824ba4cc76fd8e2657d0527c12d8
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058894::caseD_3(void)

{
  short sVar1;
  undefined2 uVar3;
  int iVar2;
  uint *puVar4;
  int unaff_s1;
  int *piVar5;
  
  sVar1 = *(short *)(unaff_s1 + 500);
  *(short *)(unaff_s1 + 500) = sVar1 + 1;
  *(int *)(unaff_s1 + 0x2c) = *(int *)(unaff_s1 + 0x2c) + sVar1 * 0x1e;
  uVar3 = FUN_80069f1c(unaff_s1 + 0x28,*(undefined2 *)(unaff_s1 + 0x136),0x8000,0);
  *(undefined2 *)(unaff_s1 + 0x25e) = uVar3;
  *(char *)(unaff_s1 + 0x1a2) = -(char)(*(int *)(unaff_s1 + 0x2c) / 0x708);
  puVar4 = &DAT_800e18f8;
  if (&DAT_800e18f8 < DAT_800e85f8) {
    piVar5 = &DAT_800e1a1c;
    do {
      if (((*puVar4 & 1) != 0) && ((*puVar4 & 2) == 0)) {
        FUN_80050eb8(puVar4);
        iVar2 = FUN_8004f774(unaff_s1 + 0x28,puVar4,*(undefined2 *)(unaff_s1 + 0x136),0);
        if ((iVar2 != 0) &&
           ((int)*(short *)(unaff_s1 + 0x25e) == *piVar5 - (uint)*(ushort *)((int)piVar5 + 0x16))) {
          *(uint **)(unaff_s1 + 0x280) = puVar4;
          break;
        }
      }
      puVar4 = puVar4 + 0xda;
      piVar5 = piVar5 + 0xda;
    } while (puVar4 < DAT_800e85f8);
  }
  if (*(int *)(unaff_s1 + 0x280) != 0) {
    FUN_8004f634(&DAT_800e1130,*(int *)(unaff_s1 + 0x280),(uint)*(byte *)(unaff_s1 + 9) << 8,0x30);
  }
  FUN_80089d54();
  if ((*(short *)(unaff_s1 + 0x1a8) < *(short *)(unaff_s1 + 0x25e)) &&
     (*(char *)(unaff_s1 + 0x207) == '\0')) {
    *(undefined1 *)(unaff_s1 + 0x207) = 0x85;
  }
  if ((*(byte *)(unaff_s1 + 0x207) & 0x7f) != 0) {
    *(byte *)(unaff_s1 + 0x207) = *(byte *)(unaff_s1 + 0x207) - 1;
    FUN_8005c3e8();
  }
  if (*(short *)(unaff_s1 + 0x25e) + -300 < *(int *)(unaff_s1 + 0x2c)) {
    *(undefined1 *)(unaff_s1 + 7) = 4;
    FUN_80052bd0(1,0);
    FUN_80052c6c(6,0x96,0);
  }
  return;
}
