/* FUN_800986a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800986a4  body 0x800986a4..0x800988a3  size 512 B
 * body sha256 2759a099cb70bd64962db3336ec318cee3eb5d4733ec7995a14b24b011efb78d
 * provider record sha256 963d3f48480772baaada9bc99f4cda98bc02b7b4b39935acf7237a9fb6c501d5
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800986a4(int param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = DAT_800c52dc;
  iVar7 = 2;
  iVar6 = 2;
  iVar3 = DAT_800c52dc + 0x3fb00;
  iVar4 = DAT_800c52dc + 0x3f800;
  puVar1 = (undefined4 *)(DAT_800c52dc + 0x3fb0c);
  do {
    iVar6 = iVar6 + -1;
    FUN_80047b04(iVar3,0);
    FUN_8004786c(iVar3,0x80,0x80,0x80);
    FUN_800478ac(iVar3,0,0);
    FUN_800479bc(iVar3,0x70,0x48);
    *(undefined2 *)((int)puVar1 + -2) = 0;
    *puVar1 = &DAT_8012fa38;
    puVar1 = puVar1 + 5;
    iVar3 = iVar3 + 0x14;
  } while (iVar6 != 0);
  if (param_1 != 0) {
    puVar1 = (undefined4 *)(iVar8 + 0x3f80c);
    do {
      FUN_80047b04(iVar4,1);
      FUN_80047854(iVar4,0,0,0x70,0x48);
      FUN_8004786c(iVar4,0x80,0x80,0x80);
      *(undefined2 *)((int)puVar1 + -2) = 0;
      *puVar1 = &DAT_8012fa38;
      puVar1 = puVar1 + 5;
      iVar7 = iVar7 + -1;
      iVar4 = iVar4 + 0x14;
    } while (iVar7 != 0);
    iVar8 = 8;
    puVar2 = &DAT_80131474;
    do {
      iVar8 = iVar8 + -1;
      iVar6 = 2;
      puVar5 = (undefined2 *)(iVar3 + 10);
      iVar4 = iVar3;
      do {
        FUN_80047b04(iVar4,0);
        FUN_8004786c(iVar4,0x80,0x80,0x80);
        iVar6 = iVar6 + -1;
        FUN_800478ac(iVar4,*puVar2,puVar2[1]);
        iVar3 = iVar4 + 0x14;
        FUN_800479bc(iVar4,puVar2[2],puVar2[3]);
        *(undefined **)(puVar5 + 1) = &DAT_8012f530;
        *puVar5 = 0;
        puVar5 = puVar5 + 10;
        iVar4 = iVar3;
      } while (iVar6 != 0);
      puVar2 = puVar2 + -4;
    } while (iVar8 != 0);
    DAT_8012fe54 = 0x10;
    DAT_8012fe56 = 10;
    DAT_8012fe58 = 0x70;
    DAT_8012fe5a = 0x48;
    DAT_8012fe64 = 0;
  }
  return;
}
