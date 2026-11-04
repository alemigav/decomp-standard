/* FUN_80090e10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80090e10  body 0x80090e10..0x8009109b  size 652 B
 * body sha256 2bbddbd0bca314255f6e4415db65fbb69c466206240da5f205c41e70e6a31124
 * provider record sha256 504345fac27a173c3e795b2b6c4d74d120d6eaed762a9b70d034ee8265be457b
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80090e10(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  
  uVar9 = (uint)DAT_8012bfb2;
  iVar4 = 2;
  iVar1 = DAT_800c52dc + 0x40800;
  puVar2 = (undefined2 *)(DAT_800c52dc + 0x4080a);
  do {
    FUN_80047b04(iVar1,0);
    FUN_8004786c(iVar1,0x80,0x80,0x80);
    FUN_800478ac(iVar1,0,0);
    FUN_800479bc(iVar1,0xc,0xc);
    *(undefined **)(puVar2 + 1) = &DAT_8012f584;
    *puVar2 = 0x20;
    puVar2 = puVar2 + 10;
    iVar4 = iVar4 + -1;
    iVar1 = iVar1 + 0x14;
  } while (iVar4 != 0);
  iVar4 = 2;
  sVar7 = 0xe;
  while( true ) {
    iVar4 = iVar4 + -1;
    iVar5 = 2;
    puVar2 = (undefined2 *)(iVar1 + 10);
    do {
      FUN_80047b04(iVar1,1);
      FUN_8004786c(iVar1,0x80,0x80,0x80);
      FUN_800478ac(iVar1,sVar7,0xc);
      FUN_800479bc(iVar1,0xe,0xc);
      *(undefined **)(puVar2 + 1) = &DAT_8012f584;
      *puVar2 = 0x40;
      puVar2 = puVar2 + 10;
      iVar5 = iVar5 + -1;
      iVar1 = iVar1 + 0x14;
    } while (iVar5 != 0);
    if (iVar4 == 0) break;
    sVar7 = sVar7 + -0xe;
  }
  iVar4 = 2;
  puVar3 = &DAT_8012fa14;
  do {
    iVar4 = iVar4 + -1;
    iVar6 = 2;
    puVar2 = (undefined2 *)(iVar1 + 10);
    iVar5 = iVar1;
    do {
      FUN_80047b04(iVar5,1);
      FUN_8004786c(iVar5,0x80,0x80,0x80);
      iVar6 = iVar6 + -1;
      FUN_800478ac(iVar5,*puVar3,puVar3[1]);
      iVar1 = iVar5 + 0x14;
      FUN_800479bc(iVar5,puVar3[2],puVar3[3]);
      *(undefined **)(puVar2 + 1) = &DAT_8012f5a0;
      *puVar2 = 0;
      puVar2 = puVar2 + 10;
      iVar5 = iVar1;
    } while (iVar6 != 0);
    puVar3 = puVar3 + -4;
  } while (iVar4 != 0);
  uVar8 = (uint)(byte)(&DAT_80130cb8)[uVar9 * 8];
  puVar3 = (&PTR_DAT_80130cb4)[uVar9 * 2] + uVar8 * 0x10;
  do {
    uVar8 = uVar8 - 1;
    iVar5 = 2;
    puVar2 = (undefined2 *)(iVar1 + 10);
    iVar4 = iVar1;
    do {
      FUN_80047b04(iVar4,1);
      FUN_8004786c(iVar4,0x80,0x80,0x80);
      iVar5 = iVar5 + -1;
      FUN_800478ac(iVar4,puVar3[-0x10],puVar3[-0xf]);
      iVar1 = iVar4 + 0x14;
      FUN_800479bc(iVar4,puVar3[-0xe],puVar3[-0xd]);
      *(undefined **)(puVar2 + 1) = &DAT_8012f5a0;
      *puVar2 = 0x20;
      puVar2 = puVar2 + 10;
      iVar4 = iVar1;
    } while (iVar5 != 0);
    puVar3 = puVar3 + -0x10;
  } while (uVar8 != 0);
  FUN_80090b3c();
  return;
}
