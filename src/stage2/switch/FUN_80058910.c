/* FUN_80058910
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058910  body 0x80058910..0x800589a3  size 148 B
 * body sha256 67741d363ff808a754a1a504a455505623196bd782b10fa7d3da988d055cfa1c
 * provider record sha256 414ebb2297fe3eab889a3e148ced7e7ad345e2215c4d37db9476852a11c8438b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_80058894::caseD_2(void)

{
  short sVar1;
  undefined2 uVar3;
  int iVar2;
  uint *puVar4;
  int unaff_s1;
  int *piVar5;
  
  *(undefined1 *)(unaff_s1 + 7) = 3;
  *(undefined4 *)(unaff_s1 + 0x1e8) = 0x8000000;
  *(undefined2 *)(unaff_s1 + 0x1e0) = 1000;
  *(undefined2 *)(unaff_s1 + 500) = 0;
  *(undefined2 *)(unaff_s1 + 500) = 5;
  *(int *)(unaff_s1 + 0x2c) = *(int *)(unaff_s1 + 0x2c) + 0x226;
  *(byte *)(unaff_s1 + 0x26f) = *(byte *)(unaff_s1 + 0x26f) | 0x80;
  if (*(char *)(unaff_s1 + 8) == '\x0f') {
    *(undefined2 *)(unaff_s1 + 0x1e0) = 600;
    *(undefined2 *)(unaff_s1 + 500) = 3;
    *(int *)(unaff_s1 + 0x2c) = *(int *)(unaff_s1 + 0x2c) + -400;
  }
  *(undefined2 *)(unaff_s1 + 0x1e4) = 0;
  FUN_80032b5c();
  *(undefined1 *)(unaff_s1 + 0x207) = 0;
  *(char *)(unaff_s1 + 0x1a2) = *(char *)(unaff_s1 + 0x1a2) + -1;
  *(undefined2 *)(unaff_s1 + 0x1b4) = *(undefined2 *)(unaff_s1 + 0x2a);
  *(undefined2 *)(unaff_s1 + 0x1b6) = *(undefined2 *)(unaff_s1 + 0x32);
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
