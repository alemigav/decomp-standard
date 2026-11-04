/* FUN_80098f10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80098f10  body 0x80098f10..0x800990d3  size 452 B
 * body sha256 c3cfaab37d06855dd0e457113e846525171a863fd1fff2024af1d9753c26bd87
 * provider record sha256 24c2df0a3add1b4af6e3e1dea2640962297121f43003866516c10edff5c46276
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80098f10(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  
  iVar4 = 4;
  puVar5 = &UNK_8012ea80;
  DAT_801315f8 = 0x1c8;
  DAT_801315fa = (DAT_8012bfe6 + 0x46) * 4;
  FUN_800428e0(0xcf);
  FUN_800828ac(&DAT_80131498,&DAT_801314a4);
  DAT_8013149c = 0x21c;
  iVar6 = 0x1e;
  do {
    puVar5 = puVar5 + -0xaa0;
    iVar4 = iVar4 + -1;
    FUN_80042af4(0);
    FUN_800990d4(puVar5,0,iVar4);
    uVar3 = 0x10;
    if (iVar4 != 3) {
      uVar3 = 8;
    }
    do {
      uVar3 = uVar3 - 1;
      iVar1 = (iVar6 + uVar3) * 0x110;
      if ((iVar4 == DAT_8012bfa9) && (uVar3 == (int)DAT_8012bfaa)) {
        *(undefined4 *)(&UNK_8012c1c4 + iVar1) = DAT_8012f930;
      }
      else {
        *(undefined4 *)(&UNK_8012c1c4 + iVar1) = DAT_8012f934;
      }
      if (iVar4 == 3) {
        if ((DAT_800e901b != 0xff) && (uVar2 = 2, uVar3 < DAT_800e901b)) goto LAB_80099084;
      }
      else {
        uVar2 = 1;
        if ((&DAT_800e8ff4)[iVar4 * 8 + uVar3] != -1) {
LAB_80099084:
          FUN_800990d4(&UNK_8012c110 + iVar1,uVar2,uVar3);
        }
      }
    } while (uVar3 != 0);
    FUN_80042ad8();
    iVar6 = iVar6 + -10;
    if (iVar4 == 0) {
      return;
    }
  } while( true );
}
