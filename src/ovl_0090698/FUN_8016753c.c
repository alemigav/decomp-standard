/* FUN_8016753c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016753c  body 0x8016753c..0x80167687  size 332 B
 * body sha256 3abe73658e44a9e4593190771ef055f02c44a4dc7145594f1060e89140460dc8
 * provider record sha256 c9da6ac39e3f2878c39ec572054bf290ae5e79f5966bfc1a84c974610d9a84f2
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8016753c(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar2 = 1;
  if (*(char *)(param_1 + 0x2d8) != '\x0e') {
    uVar3 = func_0x80033604();
    uVar3 = uVar3 & 7;
    if ((*(byte *)(param_1 + 0x2bd) < 3) ||
       (((int)(uint)*(byte *)(param_1 + 700) >> uVar3 & 1U) != 0)) {
      FUN_8016703c(param_1,0x13,1);
      uVar2 = 1;
    }
    else {
      uVar6 = uVar3 * 2 + 3;
      uVar5 = uVar3 * 2 + 4;
      *(byte *)(param_1 + 700) = *(byte *)(param_1 + 700) | (byte)(1 << uVar3);
      *(char *)(param_1 + 0x2bd) = *(char *)(param_1 + 0x2bd) + -1;
      if (uVar6 <= uVar5) {
        iVar8 = uVar6 * 0x178;
        uVar3 = uVar6;
        do {
          puVar4 = (uint *)(*(int *)(param_1 + 0x234) + iVar8);
          uVar7 = *puVar4;
          if ((DAT_800e9012 & 8) != 0) {
            uVar7 = uVar7 | 0x4a;
          }
          *puVar4 = uVar7;
          sVar1 = *(short *)(param_1 + 0x66);
          uVar3 = uVar3 + 1;
          *(undefined2 *)(puVar4 + 0x4e) = 0;
          *(undefined2 *)(puVar4 + 0x4d) = 600;
          *(undefined2 *)((int)puVar4 + 0x132) = 0xff88;
          *(undefined2 *)((int)puVar4 + 0x136) = 10;
          *(undefined2 *)(puVar4 + 0x4f) = 0xff9c;
          puVar4[0x18] = 0x2f2f2f;
          *(short *)(puVar4 + 0x4c) = sVar1 + 0x800;
          iVar8 = iVar8 + 0x178;
        } while (uVar3 <= uVar5);
      }
      FUN_8016703c(param_1,uVar6,1);
      uVar2 = 0;
    }
  }
  return uVar2;
}
