/* FUN_80030f18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030f18  body 0x80030f18..0x80030f77  size 96 B
 * body sha256 d0c7204b0147f3df67f5548a7e411b996970af7e23c212196033571b3d32c4ee
 * provider record sha256 6a8ae50a20feb3709d9c6e297d92e9b9ab2c1a89462334d7cb82df9914eed4cc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80030f18(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  puVar3 = (undefined4 *)(param_1 + param_2 * 4);
  puVar5 = (undefined4 *)(param_3 + param_4 * 4);
  for (; 0 < param_5; param_5 = param_5 + -1) {
    puVar6 = (undefined1 *)*puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = (undefined1 *)*puVar5;
    puVar5 = puVar5 + 1;
    for (iVar2 = param_6; iVar2 != 0; iVar2 = iVar2 + -1) {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}
