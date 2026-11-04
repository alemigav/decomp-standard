/* FUN_80009170
 * image   boot (boot), base 0x80000480
 * address 0x80009170  body 0x80009170..0x8000925f  size 240 B
 * body sha256 14ebee9f4bdc10edd897ce8134acd42bb205e946c2eface104c81c17cbe0dd25
 * provider record sha256 6a4b560794184ce0eb0a7ccd1f8ba644361eb25f6819eff61331fb3171c0aceb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80009170(uint *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  uint *puVar6;
  float *pfVar7;
  float fVar8;
  float fVar9;
  float local_40 [16];
  
  pfVar5 = local_40;
  pfVar4 = local_40;
  pfVar7 = local_40;
  iVar3 = 0;
  do {
    iVar1 = 0;
    puVar2 = pfVar4;
    do {
      if (iVar3 == iVar1) {
        *pfVar5 = 1.0;
      }
      else {
        *puVar2 = 0;
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < 4);
    pfVar5 = pfVar5 + 5;
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 4;
  } while (iVar3 < 4);
  puVar6 = param_1 + 8;
  iVar3 = 0;
  do {
    iVar1 = 0;
    pfVar4 = pfVar7;
    do {
      fVar9 = *pfVar4;
      fVar8 = pfVar4[1];
      pfVar4 = pfVar4 + 2;
      iVar1 = iVar1 + 1;
      *param_1 = (int)(fVar9 * 65536.0) & 0xffff0000U | (uint)(int)(fVar8 * 65536.0) >> 0x10;
      param_1 = param_1 + 1;
      *puVar6 = (int)(fVar9 * 65536.0) << 0x10 | (int)(fVar8 * 65536.0) & 0xffffU;
      puVar6 = puVar6 + 1;
    } while (iVar1 < 2);
    iVar3 = iVar3 + 1;
    pfVar7 = pfVar7 + 4;
  } while (iVar3 < 4);
  return;
}
