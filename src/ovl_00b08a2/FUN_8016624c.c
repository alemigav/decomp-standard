/* FUN_8016624c
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x8016624c  body 0x8016624c..0x801664db  size 656 B
 * body sha256 9bad7db3e60b572ae1b026c7ec9b3b4d2a43591279f3bc17c923239e83e1a990
 * provider record sha256 77cd7958a016c5a7e41c63a06eba3fe273e5ae786fc5e220f819a72f617e547e
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016624c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  undefined1 auStack_40 [32];
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x5000700;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    func_0x80077adc(0x4020001,param_1 + 10);
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
    local_1e = func_0x80032d14((int)*(short *)((int)param_1 + 0x2a),
                               (int)*(short *)((int)param_1 + 0x32),
                               (int)*(short *)(_DAT_800e13f0 + 0x2a),
                               (int)*(short *)(_DAT_800e13f0 + 0x32));
    local_20 = 0;
    local_1c = 0;
    func_0x80040e58(&local_20,auStack_40);
    local_20 = 600;
    local_1e = 0;
    func_0x8004276c(auStack_40,&local_20,param_1 + 0x78);
  case 1:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      param_1[0x7a] = 0x3000300;
      *(undefined1 *)((int)param_1 + 6) = 2;
      *(undefined2 *)(param_1 + 0x7d) = 0xf;
    }
    param_1[10] = param_1[10] + (int)*(short *)(param_1 + 0x78);
    param_1[0xc] = param_1[0xc] + (int)*(short *)(param_1 + 0x79);
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) >> 1;
    *(short *)(param_1 + 0x79) = *(short *)(param_1 + 0x79) >> 1;
    if ((*(char *)((int)param_1 + 0x1e9) == '\x03') || (*(char *)((int)param_1 + 0x1e9) == '\v')) {
      func_0x80077f30(2,0,param_1);
    }
    break;
  case 2:
    func_0x80089d54(param_1,param_2,param_3,0x400);
    sVar1 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar1 + -1;
    if ((short)(sVar1 + -1) == -1) {
      param_1[0x7a] = 0x1000300;
      *(undefined1 *)((int)param_1 + 6) = 3;
    }
    break;
  case 3:
    iVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
    if (iVar2 != 0) {
      param_1[0x7a] = 0x6000700;
      *(undefined1 *)((int)param_1 + 6) = 4;
      *(undefined1 *)(param_1 + 0x97) = 0;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *param_1 = *param_1 & 0xfffffffd;
      _DAT_800e110c = _DAT_800e110c & 0xffffffbf;
    }
    break;
  case 4:
    iVar2 = func_0x80089d54(param_1,param_1[0x69],param_1[0x86],0x10200);
    if (iVar2 != 0) {
      param_1[1] = 0x1000000;
    }
  }
  return;
}
