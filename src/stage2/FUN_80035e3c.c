/* FUN_80035e3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035e3c  body 0x80035e3c..0x80036007  size 460 B
 * body sha256 62083380919f3c17e5af5771be5c3583670b2dc93de0e32b26513839d674b317
 * provider record sha256 4f055a52e5a706f8a1b0c6308acc44304f36d4a262c73aa46205afdcbb35eebe
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035e3c(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  uVar9 = *(undefined4 *)(param_1 + 0x234);
  FUN_80036290(param_1,uVar9,&DAT_800eb8e8);
  FUN_80036734(param_1,uVar9);
  if ((DAT_800e110c & 0x10000) != 0) {
    if ((DAT_800e10f1 == '\x02') ||
       (cVar8 = FUN_8004a328(*(int *)(DAT_800df92c + 0x24) + DAT_800e8cac * 0x20,DAT_800e10f1,
                             param_1 + 0x28), cVar8 != '\0')) {
      FUN_8004a0a8(param_1);
      uVar10 = *(undefined4 *)(param_1 + 0x234);
      *(undefined4 *)(param_1 + 0x234) = *(undefined4 *)(param_1 + 0x240);
      FUN_80036290(param_1,uVar9,&DAT_800eb8e8);
      uVar7 = DAT_800e9150;
      uVar6 = DAT_800e914c;
      uVar5 = DAT_800e9148;
      uVar4 = DAT_800e9144;
      uVar3 = DAT_800e9140;
      uVar2 = DAT_800e913c;
      uVar1 = DAT_800e9138;
      uVar9 = DAT_800e9134;
      DAT_800e9134 = DAT_800e9154;
      DAT_800e9138 = DAT_800e9158;
      DAT_800e913c = DAT_800e915c;
      DAT_800e9140 = DAT_800e9160;
      DAT_800e9144 = DAT_800e9164;
      DAT_800e9148 = DAT_800e9168;
      DAT_800e914c = DAT_800e916c;
      DAT_800e9150 = DAT_800e9170;
      FUN_80036734(param_1,*(undefined4 *)(param_1 + 0x234));
      DAT_800e9134 = uVar9;
      DAT_800e9138 = uVar1;
      DAT_800e913c = uVar2;
      DAT_800e9140 = uVar3;
      DAT_800e9144 = uVar4;
      DAT_800e9148 = uVar5;
      DAT_800e914c = uVar6;
      DAT_800e9150 = uVar7;
      *(undefined4 *)(param_1 + 0x234) = uVar10;
    }
  }
  return;
}
