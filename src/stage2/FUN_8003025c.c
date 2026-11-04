/* FUN_8003025c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003025c  body 0x8003025c..0x80030323  size 200 B
 * body sha256 89231560ec5ef57733fe27fdfed5052832d5c11c1f200ad91cf42c836049f098
 * provider record sha256 e6d37ccee75b6680c29b5102fe464b51812aee5db6ec1cee30a78f375df0b335
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003025c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  if (param_2 != 1) {
    *(undefined4 *)(*param_1 + 0x14) = 0xb;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)();
  }
  uVar1 = FUN_80030edc(param_4,param_5);
  puVar2 = (undefined4 *)FUN_8002fd38(param_1,param_2,0x74);
  *puVar2 = 0;
  puVar2[1] = uVar1;
  puVar2[2] = param_3;
  puVar2[3] = param_5;
  puVar2[8] = 0;
  puVar2[9] = *(undefined4 *)(iVar3 + 0x40);
  *(undefined4 **)(iVar3 + 0x40) = puVar2;
  return;
}
