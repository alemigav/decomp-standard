/* FUN_800661e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800661e4  body 0x800661e4..0x80066287  size 164 B
 * body sha256 1330b0cd28ba47fc74a3a4dba02e25189c7dbbae2d1ffb26b8b0fab33ca248b0
 * provider record sha256 2de54519a90fb4631eba87b594584ed6bad09c602849581e758b0171717e88d8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800661e4(int param_1,uint *param_2)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  *(uint **)(param_1 + 600) = param_2;
  if ((param_2 != (uint *)0x0) && (uVar9 = 0, *param_2 != 0)) {
    puVar3 = param_2 + 3;
    puVar6 = (undefined4 *)(*(int *)(param_1 + 0x234) + 0x120);
    iVar8 = *(int *)(*(int *)(param_1 + 0xc4) + 4);
    do {
      *puVar6 = 0;
      puVar5 = puVar3 + 3;
      if ((*param_2 & 1 << (uVar9 & 0x1f)) != 0) {
        *puVar6 = puVar3;
        uVar7 = puVar3[2];
        puVar2 = (undefined2 *)((int)puVar3 + 0xe);
        uVar4 = uVar7;
        while( true ) {
          uVar4 = uVar4 - 1;
          if (uVar4 == 0xffffffff) break;
          uVar1 = *(undefined2 *)puVar5;
          *(undefined2 *)puVar5 = *puVar2;
          *puVar2 = uVar1;
          puVar2 = puVar2 + 2;
          puVar5 = puVar5 + 1;
        }
        puVar3 = puVar3 + uVar7 + 3;
      }
      puVar6 = puVar6 + 0x5e;
      iVar8 = iVar8 + -1;
      uVar9 = uVar9 + 1;
    } while (iVar8 != 0);
  }
  return;
}
