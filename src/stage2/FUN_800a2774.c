/* FUN_800a2774
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2774  body 0x800a2774..0x800a294f  size 476 B
 * body sha256 3ac4717a32f5b1cd84e654256a042b300507922527c6756ffaca4ecb8babc7c6
 * provider record sha256 ffb7c0c169db2fee8f91d2db4560e18730318e4995937ba26b0094ec2a2ab580
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a2774(ushort *param_1)

{
  ushort *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  
  if (_DAT_80143f70 != 0) {
    iVar10 = (((uint)*param_1 * _DAT_80143f04) / 0x2ee00) * 0xc0 + 0xc0;
    piVar3 = (int *)(*_DAT_80144008)(0x48,0);
    iVar2 = _DAT_80143f70;
    iVar9 = iVar10 * 2;
    *piVar3 = _DAT_80143f70;
    func_0x80006650(iVar2,iVar9);
    func_0x8000efa0(*piVar3,iVar9);
    piVar3[1] = iVar10;
    *(ushort *)((int)piVar3 + 10) = (ushort)*(byte *)((int)param_1 + 0x1b) << 8;
    *(ushort *)(piVar3 + 2) = (ushort)*(byte *)(param_1 + 0xd);
    iVar2 = _DAT_80143f04;
    if (*(char *)(param_1 + 0xd) != '\0') {
      piVar7 = piVar3;
      uVar5 = 0;
      puVar6 = param_1;
      piVar8 = piVar3;
      do {
        puVar1 = puVar6 + 1;
        puVar6 = puVar6 + 1;
        uVar4 = uVar5 + 1;
        piVar7[3] = (iVar2 * (uint)*puVar1) / 1000 + 3 & 0xfffc;
        piVar7 = piVar7 + 1;
        *(ushort *)(piVar8 + 0xb) = (ushort)*(byte *)((int)param_1 + uVar5 + 0x12) << 8;
        piVar8 = (int *)((int)piVar8 + 2);
        uVar5 = uVar4;
      } while (uVar4 < *(byte *)(param_1 + 0xd));
    }
    if (*(char *)(param_1 + 0xe) == '\x01') {
      uVar5 = 0;
      piVar7 = piVar3;
      do {
        puVar6 = param_1 + 0xf;
        param_1 = param_1 + 1;
        uVar5 = uVar5 + 1;
        *(ushort *)(piVar7 + 0x10) = *puVar6;
        piVar7 = (int *)((int)piVar7 + 2);
      } while (uVar5 < 4);
    }
    else {
      *(undefined2 *)(piVar3 + 0x10) = 0;
      *(undefined2 *)((int)piVar3 + 0x42) = 0;
      *(undefined2 *)(piVar3 + 0x11) = 0;
      *(undefined2 *)((int)piVar3 + 0x46) = 0x7fff;
    }
    func_0x8000efa0(piVar3,0x48);
    FUN_800a5678();
    _DAT_80143f6c = 0;
    _DAT_80143f68 = piVar3;
    FUN_800a56c0();
  }
  return;
}
