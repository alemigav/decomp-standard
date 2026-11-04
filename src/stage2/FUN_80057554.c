/* FUN_80057554
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80057554  body 0x80057554..0x80057717  size 452 B
 * body sha256 d3000f96693163c9609c1d5c7d88e42154090d57cca79b70ffaded14ccb835ab
 * provider record sha256 508801a692ae1128661bd27dee11726a32b34972ba7d35225eed3e1e851230e6
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80057554(int param_1,uint param_2,short param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  
  puVar8 = (uint *)0x0;
  if (DAT_800e1126 != '\0') {
    puVar7 = &DAT_800e13f0;
    do {
      puVar6 = (uint *)*puVar7;
      if (((*puVar6 & 1) != 0) && ((*(ushort *)((int)puVar6 + 0x1aa) & 0xe000) == 0)) {
        iVar2 = *(int *)(param_1 + 0x28) - puVar6[10];
        iVar3 = *(int *)(param_1 + 0x30) - puVar6[0xc];
        bVar1 = false;
        uVar4 = FUN_80040bb4(iVar2 * iVar2 + iVar3 * iVar3);
        if ((-1 < *(short *)((int)puVar6 + 0x1f2)) &&
           ((iVar2 = FUN_8006ab40(*(int *)(param_1 + 0x234) +
                                  (uint)*(byte *)(param_1 + 0x25d) * 0x178 + 0x4c,
                                  puVar6[0x8d] + (uint)*(byte *)((int)puVar6 + 0x25d) * 0x178 + 0x4c
                                  ,0x2080), iVar2 == 0 &&
            (iVar2 = FUN_80032e74(param_1,puVar6[10],puVar6[0xc],(int)param_3), iVar2 == 0)))) {
          cVar5 = FUN_80033144(param_1,puVar6);
          bVar1 = cVar5 == '\0';
        }
        if ((bVar1) && (uVar4 < param_2)) {
          param_2 = uVar4;
          puVar8 = puVar6;
        }
      }
      puVar7 = puVar7 + 1;
    } while (puVar7 != DAT_800df93c);
    if (puVar8 != (uint *)0x0) {
      *(uint **)(param_1 + 0x250) = puVar8;
      return 1;
    }
  }
  *(int *)(param_1 + 0x250) = param_1;
  return 0;
}
