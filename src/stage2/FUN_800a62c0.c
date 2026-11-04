/* FUN_800a62c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a62c0  body 0x800a62c0..0x800a64c7  size 520 B
 * body sha256 cb8e69c96ff72a7bb09e84a2f0d3c0e5aa9acbaef3316598d066ea630f539ef7
 * provider record sha256 7c810e6e5b65f8d007cc1ff8cb04a4cdd72db514eb9da4bd2c457fa460d9ea86
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800a62c0(ushort param_1,char param_2,char param_3)

{
  ushort uVar1;
  char cVar2;
  uint *puVar3;
  undefined1 *unaff_s1;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  uint unaff_s6;
  
  puVar6 = &DAT_80144448;
  iVar7 = -1;
  uVar4 = 0;
  if (DAT_80147a58 != 0) {
    puVar3 = (uint *)&DAT_801444a8;
    puVar5 = &DAT_80144448;
    do {
      if ((((*puVar3 != 0xffffffff) && (*(char *)((int)puVar3 + -0x16) == param_2)) &&
          (*(char *)((int)puVar3 + -0x15) == param_3)) &&
         ((((puVar3[-0xf] & 0x10) != 0 && ((puVar3[-0xf] & 0x40000008) != 8)) &&
          (cVar2 = FUN_800a5890(uVar4), cVar2 != '\0')))) {
        cVar2 = *(char *)(puVar3 + 0x18);
        *(ushort *)((int)puVar3 + -0x12) = param_1 & 0xff;
        *(undefined1 *)(puVar3 + 0x18) = 0;
        puVar3[0xb] = 0;
        *(byte *)((int)puVar3 + 0x61) = *(byte *)((int)puVar3 + -0xf);
        uVar1 = *(ushort *)(puVar3 + -4);
        *(ushort *)(puVar3 + -4) =
             (param_1 & 0xff) +
             ((ushort)*(byte *)((int)puVar3 + -0xf) - (ushort)*(byte *)((int)puVar3 + -0x11));
        puVar3[-0xf] = puVar3[-0xf] | 0x80000;
        puVar3[0xd] = (uint)uVar1 * 0x10000 + ((int)cVar2 << 0x10) / 100;
        FUN_800ae1a0(puVar5);
        unaff_s1 = puVar6;
        if (iVar7 == -1) {
          puVar3[-0x14] = 0xffffffff;
          puVar3[-0x13] = 0xffffffff;
          iVar7 = FUN_800ae300(puVar5);
          unaff_s6 = *puVar3;
        }
        else {
          *(undefined4 *)((unaff_s6 & 0xff) * 0x1a0 + -0x7febbba8) = *(undefined4 *)(puVar6 + 0x60);
          *(uint *)(puVar6 + 0x14) = unaff_s6;
          unaff_s6 = *(uint *)(puVar6 + 0x60);
        }
      }
      puVar5 = puVar5 + 0x1a0;
      uVar4 = uVar4 + 1;
      puVar3 = puVar3 + 0x68;
      puVar6 = puVar6 + 0x1a0;
    } while (uVar4 < DAT_80147a58);
  }
  if (iVar7 != -1) {
    FUN_800b1b84(unaff_s1);
    FUN_800ac69c(unaff_s1[0x4a],unaff_s1[0x4b],unaff_s1[0x51]);
  }
  return iVar7;
}
