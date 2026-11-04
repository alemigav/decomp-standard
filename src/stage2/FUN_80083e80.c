/* FUN_80083e80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083e80  body 0x80083e80..0x80083f87  size 264 B
 * body sha256 e404538684cc754c68953ae1f9aef2eee0e8ce319b429bce408eb46da3a3260f
 * provider record sha256 54acc5b73ea0dc085d012717c2c4b52d1cc09439b01e430e20e770f1ee7d4381
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80083e80(float param_1,float param_2,undefined4 param_3,undefined4 param_4,float param_5,
                 float param_6,float param_7,float param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = param_5 - param_1;
  fVar2 = param_6 - param_2;
  fVar1 = (param_7 - param_1) * fVar3 + (param_8 - param_2) * fVar2;
  if (fVar1 == 0.0) {
    if (param_7 == param_1) {
      param_5 = param_1;
      param_6 = param_2;
      goto LAB_80083f6c;
    }
  }
  else {
    fVar1 = fVar1 / (fVar3 * fVar3 + fVar2 * fVar2);
    if (fVar1 < 0.0) {
      param_5 = param_1;
      param_6 = param_2;
      goto LAB_80083f6c;
    }
    if (fVar1 <= 1.0) {
      param_5 = param_1 + fVar1 * fVar3;
      param_6 = param_2 + fVar1 * fVar2;
      param_7 = param_1;
      param_8 = param_2;
      goto LAB_80083f6c;
    }
  }
LAB_80083f6c:
  FUN_80083e60(param_7,param_8,param_3,param_4,param_5,param_6);
  return;
}
