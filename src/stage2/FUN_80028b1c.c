/* FUN_80028b1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028b1c  body 0x80028b1c..0x80028c57  size 316 B
 * body sha256 440683c8e4dad56aa5bbb3b79ef872453417526f0ddd8477a2dfef46090906d3
 * provider record sha256 797627e6b552e959c2071bed42edfc94fb94b6317819314b720bad468f0bba81
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80028b1c(int *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_1[4] != 0xcc) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_1[4];
    (**(code **)*param_1)();
  }
  if ((uint)param_1[0x1e] < (uint)param_1[0x18]) {
    if (param_1[2] != 0) {
      *(int *)(param_1[2] + 4) = param_1[0x1e];
      *(int *)(param_1[2] + 8) = param_1[0x18];
      (**(code **)param_1[2])(param_1);
    }
    uVar1 = param_1[0x42] * param_1[0x43];
    if (param_3 < uVar1) {
      *(undefined4 *)(*param_1 + 0x14) = 0x10;
      (**(code **)*param_1)(param_1);
    }
    iVar2 = (**(code **)(param_1[0x5b] + 4))(param_1,param_2);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      param_1[0x1e] = param_1[0x1e] + uVar1;
    }
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 0x6d;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    uVar1 = 0;
  }
  return uVar1;
}
