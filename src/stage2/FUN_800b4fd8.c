/* FUN_800b4fd8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4fd8  body 0x800b4fd8..0x800b50ab  size 212 B
 * body sha256 79c2ac9f85cb965461a09e8a05877af94c41c0feae29bf88348e406a85587bc3
 * provider record sha256 619a05d8f24b9c3f64281cf09f80b252b1e43170f2e3193006dd7d59b06e5151
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b4fd8(undefined4 param_1,undefined4 param_2,short *param_3,short *param_4,short *param_5
                 ,short *param_6,int param_7,undefined4 param_8)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined1 auStack_78 [80];
  
  iVar3 = 0;
  do {
    iVar3 = iVar3 + 1;
    FUN_800b62c0((int)*param_6,(int)*param_5,param_7,auStack_78);
    sVar1 = *param_3;
    sVar2 = *param_4;
    param_4 = param_4 + 1;
    param_3 = param_3 + 1;
    FUN_800b63b4(param_1,(int)sVar1,(int)sVar2,auStack_78);
    param_6 = param_6 + 1;
    param_5 = param_5 + 1;
    param_7 = param_7 + 0x1a;
  } while (iVar3 < 4);
  FUN_800b4dc0(param_1,param_2,param_1,param_8);
  return;
}
