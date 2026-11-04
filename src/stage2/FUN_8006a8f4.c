/* FUN_8006a8f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a8f4  body 0x8006a8f4..0x8006aa4f  size 348 B
 * body sha256 f9c53e596be0296511a2960958a2f7df48a863d50f91152826e04a5fa35e6aa7
 * provider record sha256 b5057f7019813b15f190567b10a94fbedcfab651d9a870f8e7c18b66248dbe60
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006a8f4(undefined4 *param_1,short *param_2,undefined4 param_3,int param_4)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  
  uVar13 = 0xff9c;
  uVar14 = 0;
  sVar1 = *param_2;
  iVar3 = FUN_8006b220(param_2);
  iVar11 = (int)param_2[1];
  uVar2 = param_2[2];
  iVar4 = FUN_8006b264(param_2);
  uVar10 = (uint)(ushort)param_2[3];
  iVar5 = FUN_8006a75c(param_3);
  if (iVar5 == 1) {
    iVar6 = param_4 + 4;
    param_4 = param_4 + 8;
    uVar7 = param_1[1];
    uVar8 = param_1[2];
    iVar9 = iVar3;
    uVar12 = iVar4 - iVar3;
  }
  else {
    iVar9 = (int)sVar1;
    uVar12 = (uint)uVar2;
    iVar6 = param_4;
    if (iVar5 == 0) {
      param_4 = param_4 + 8;
      uVar7 = *param_1;
      uVar8 = param_1[2];
    }
    else {
      if (iVar5 != 2) {
        return;
      }
      param_4 = param_4 + 4;
      uVar7 = *param_1;
      uVar8 = param_1[1];
      iVar11 = iVar3;
      uVar10 = iVar4 - iVar3;
    }
  }
  FUN_8006aa50(uVar7,uVar8,iVar9,iVar11,uVar12,uVar10,iVar6,param_4,uVar13,uVar14);
  return;
}
