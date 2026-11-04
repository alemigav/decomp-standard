/* FUN_801632a0
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801632a0  body 0x801632a0..0x8016340f  size 368 B
 * body sha256 8fd4d62d9e40a83631677404a4985cb19d3725c9f601a45ace1f5fdd2ad0ce56
 * provider record sha256 9008cd21a8e8c30c3c059e6658350378d878360d4990bb7ff1714dc67aaae506
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801632a0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if ((1 < bVar1) || (bVar1 != 0)) goto LAB_801633f0;
    uVar5 = 0;
    iVar6 = 0;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)((int)param_1 + 0x212) = 0x1000;
    *param_1 = *param_1 | 0x800;
    do {
      uVar5 = uVar5 + 1;
      iVar3 = param_1[0x8d] + iVar6;
      iVar6 = iVar6 + 0x178;
      *(undefined4 *)(iVar3 + 0x60) = 0x3f2f5f;
    } while (uVar5 < 3);
    FUN_80163bb8(param_1,0,2);
    if (*(char *)((int)param_1 + 0x2c7) == '\0') {
      uVar5 = func_0x80033604();
      param_1[0x7a] = (uVar5 & 7) * 0x10000 + 0x5000700;
    }
  }
  sVar2 = *(short *)((int)param_1 + 0x212) + -0x20;
  *(short *)((int)param_1 + 0x212) = sVar2;
  uVar5 = 0;
  if (sVar2 < 0xa00) {
    iVar6 = 0;
    *(undefined1 *)((int)param_1 + 6) = 2;
    *(undefined2 *)((int)param_1 + 0x212) = 0xa00;
    do {
      uVar5 = uVar5 + 1;
      puVar4 = (uint *)(param_1[0x8d] + iVar6);
      *(undefined2 *)(puVar4 + 0x4c) = 0;
      *(undefined2 *)((int)puVar4 + 0x132) = 0;
      *(undefined2 *)((int)puVar4 + 0x136) = 0x1e;
      *(undefined1 *)(puVar4 + 0x4d) = 0x14;
      *(undefined1 *)((int)puVar4 + 0x135) = 0x14;
      *puVar4 = *puVar4 | 0x10;
      iVar6 = iVar6 + 0x178;
    } while (uVar5 < 3);
  }
  if (*(char *)((int)param_1 + 0x2c7) == '\0') {
    func_0x80089d54(param_1,param_2,param_3,0x100);
  }
LAB_801633f0:
  FUN_8016375c(param_1,0);
  return;
}
