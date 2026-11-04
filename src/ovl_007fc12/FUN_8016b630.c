/* FUN_8016b630
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016b630  body 0x8016b630..0x8016b81f  size 496 B
 * body sha256 f3c713d32fc87b683637d183a1d63944d99db81a727e8d2a9b11f6e1e5821f15
 * provider record sha256 1346d7d626525c7b6f2d18b5557325b2be3cc919491e1a52a44ea3af046aea17
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016b630(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  char cVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(*(short *)((int)param_1 + 0x276) * 4 + -0x7ff1ec18);
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0xa000f00;
    *(undefined1 *)((int)param_1 + 6) = 1;
    func_0x80032dbc(param_1,puVar3[10],puVar3[0xc],0x400);
    *(undefined2 *)(param_1 + 0x7d) = 0;
    func_0x80077d18(10,param_1);
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
  case 1:
    sVar1 = *(short *)(param_1 + 0x7d);
    *(ushort *)(param_1 + 0x7d) = sVar1 + 1U;
    if ((sVar1 + 1U & 1) == 0) {
      *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) >> 2;
    }
    else {
      func_0x800334c8(param_1,param_2,param_3,0);
    }
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    func_0x80032b5c(param_1,0);
    if (*(char *)((int)param_1 + 0x1e9) == '\x11') {
      *(undefined1 *)((int)param_1 + 6) = 2;
    }
    break;
  case 2:
    param_1[0x7a] = 0x18000f00;
    *(undefined1 *)((int)param_1 + 6) = 3;
    func_0x800331fc(puVar3,param_2,param_3,0);
    puVar3[1] = 0x4200000;
    puVar3[0x94] = (uint)param_1;
    puVar3[0x89] = param_1[0x89];
    puVar3[0x8a] = param_1[0x8a];
    *param_1 = *param_1 | 0x1000;
    *puVar3 = *puVar3 | 0x1000;
  case 3:
    func_0x8003331c(param_1,param_2,param_3,0);
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    break;
  case 4:
    param_1[1] = 0x8030200;
  }
  return;
}
