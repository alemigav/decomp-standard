/* FUN_80027930
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80027930  body 0x80027930..0x80027a7f  size 336 B
 * body sha256 6b96eeb71cff8290c92a2de9aa085277397aa53174ec80fecac9fdd40ba6b778
 * provider record sha256 fd4b492bfcbffd066dc91f6dbdda7815431211213ecfa5bcb904d180d50f5792
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80027930(int param_1,ushort *param_2,uint param_3)

{
  short *psVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  float local_40;
  float local_3c;
  
  uVar6 = (ulonglong)param_3;
  FUN_80082200(&local_40,0,8);
  psVar1 = (short *)(param_1 + 4);
  uVar8 = 0;
  uVar7 = 0x3f000000;
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    local_40 = (float)(int)(*param_2 - 0xa0);
    local_3c = (float)(int)(param_2[1] - 0x78);
    fVar3 = (float)func_0x80006be0((int)uVar6);
    fVar3 = local_40 * fVar3;
    fVar4 = (float)func_0x8000d050((int)uVar6);
    fVar3 = fVar3 - local_3c * fVar4;
    fVar4 = (float)func_0x8000d050((int)uVar6);
    fVar4 = local_40 * fVar4;
    fVar5 = (float)func_0x80006be0((int)uVar6);
    fVar4 = fVar4 + local_3c * fVar5;
    if ((float)uVar8 < fVar3) {
      fVar3 = fVar3 + (float)uVar7;
    }
    if ((float)uVar8 < fVar4) {
      fVar4 = fVar4 + (float)uVar7;
    }
    *psVar1 = (short)(int)fVar3 + 0xa0;
    psVar1[1] = (short)(int)fVar4 + 0x78;
    psVar1 = psVar1 + 4;
    param_2 = param_2 + 2;
  }
  return;
}
