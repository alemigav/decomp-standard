/* FUN_800584dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800584dc  body 0x800584dc..0x80058513  size 56 B
 * body sha256 66a637c45e3ca6eef6d516bb632af4665956f553badf195d8ad786e33bb6db03
 * provider record sha256 e04271a6bbd3261c130c063709877a60078cbe553db734b01aaf6e3877ff9269
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800584dc(uint *param_1)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  char cVar4;
  char cVar5;
  
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined1 *)(param_1 + 0x7a) = 6;
    if ((*(byte *)((int)param_1 + 6) & 2) != 0) {
      *(undefined1 *)(param_1 + 0x7a) = 7;
    }
    *(undefined1 *)((int)param_1 + 0x1ea) = 7;
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    param_1[0x7a] = 0x700;
    *(undefined2 *)(param_1 + 0x78) = 0x32;
    DAT_800e110c = DAT_800e110c | 0x40;
    *param_1 = *param_1 | 4;
  case 1:
    FUN_80089d54(param_1,param_1[0x87],param_1[0x88],0x200);
    uVar1 = *(ushort *)((int)param_1 + 0x66);
    if ((uVar1 & 0x200) == 0) {
      uVar2 = -(uVar1 >> 2 & 0xff);
    }
    else {
      uVar2 = uVar1 >> 2 & 0xff;
    }
    *(ushort *)((int)param_1 + 0x66) = uVar1 + uVar2;
    if ((*(ushort *)((int)param_1 + 0x66) & 0x3e0) == 0) {
      *(ushort *)((int)param_1 + 0x66) = *(ushort *)((int)param_1 + 0x66) & 0xff00;
      *(undefined1 *)((int)param_1 + 7) = 2;
      if ((*(byte *)((int)param_1 + 6) & 2) != 0) {
        *(undefined1 *)((int)param_1 + 5) = 9;
        *(undefined1 *)((int)param_1 + 7) = 0;
      }
    }
    break;
  case 2:
    *(undefined1 *)((int)param_1 + 7) = 3;
    *(undefined1 *)(param_1 + 0x7a) = 6;
    *(undefined1 *)((int)param_1 + 0x1ea) = 3;
  case 3:
    if (param_1[0xa0] != 0) {
      FUN_8004f634(&DAT_800e1130,param_1[0xa0],(uint)*(byte *)((int)param_1 + 9) << 8,4);
    }
    if (*(char *)((int)param_1 + 0x1e9) == '\x11') {
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
      *param_1 = *param_1 | 8;
      *(char *)((int)param_1 + 0x1a2) = *(char *)((int)param_1 + 0x1a2) + '\x01';
    }
    if (*(char *)(param_1 + 2) == '\x0f') {
      cVar5 = *(char *)((int)param_1 + 0x1e9);
      if (cVar5 == '9') {
        uVar3 = FUN_80033604();
        if ((uVar3 & 3) != 0) {
          param_1[0x7a] = 0x6560500;
        }
        cVar5 = *(char *)((int)param_1 + 0x1e9);
      }
      if (cVar5 == 'c') {
        *(undefined2 *)(param_1 + 0x78) = 0x224;
        FUN_80032b5c(param_1,0);
        param_1[0xb] = param_1[0xb] - 0x708;
        *(short *)((int)param_1 + 0x25e) = *(short *)((int)param_1 + 0x25e) + -0x708;
      }
      cVar5 = *(char *)((int)param_1 + 0x1e9);
      cVar4 = 'w';
    }
    else {
      cVar5 = *(char *)((int)param_1 + 0x1e9);
      if (cVar5 == '\x1d') {
        *(undefined2 *)(param_1 + 0x78) = 1000;
        FUN_80032b5c(param_1,0);
        param_1[0xb] = param_1[0xb] - 0x708;
        *(short *)((int)param_1 + 0x25e) = *(short *)((int)param_1 + 0x25e) + -0x708;
        cVar5 = *(char *)((int)param_1 + 0x1e9);
        cVar4 = '1';
      }
      else {
        cVar4 = '1';
      }
    }
    if (cVar5 == cVar4) {
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      *param_1 = *param_1 & 0xfffffff3;
    }
    cVar5 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x400);
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar5;
    if (((*(short *)(param_1 + 0x6a) < *(short *)((int)param_1 + 0x25e)) &&
        (*(byte *)((int)param_1 + 0x1e9) < 0xf)) && ((*(byte *)((int)param_1 + 0x1e9) & 1) != 0)) {
      FUN_8005c3e8(param_1);
    }
  default:
    if ((*(uint *)param_1[0x85] & 0x4000) != 0) {
      FUN_80077f30(1,((*(uint *)param_1[0x85] & 0x2000) >> 0xd) * 3 + 4,param_1);
      DAT_800e112a = DAT_800e112a | 4;
    }
    break;
  case 4:
    if (param_1[0xa0] != 0) {
      FUN_8004f634(&DAT_800e1130,param_1[0xa0],(uint)*(byte *)((int)param_1 + 9) << 8,1000);
    }
    *(undefined1 *)((int)param_1 + 5) = 0;
    *(undefined1 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 7) = 0;
    DAT_800e110c = DAT_800e110c & 0xffffffbf;
  }
  return;
}
