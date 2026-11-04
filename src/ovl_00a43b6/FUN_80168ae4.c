/* FUN_80168ae4
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80168ae4  body 0x80168ae4..0x80168ee7  size 1028 B
 * body sha256 346657ac7ba9163c2923b8e958863d688d5eb0d8713552190ab670076b69f73b
 * provider record sha256 c9e112ca1d5b7672f00a907082c4de82454fde31c7fe35740668da248508e06e
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80168ae4(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar5;
  ushort uVar3;
  uint uVar1;
  uint uVar2;
  short sVar4;
  int iVar6;
  uint *puVar7;
  short local_20;
  short local_1e;
  short local_1c;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    func_0x80052bd0(0x1e,0);
    func_0x80052c6c(0xf,0x78,0xf);
  case 1:
    if (*(char *)(param_1 + 0x1e9) == '\n') {
      func_0x80077adc(0x4030001,param_1 + 0x28);
      iVar6 = *(int *)(param_1 + 0x234);
      *(uint *)(iVar6 + 0xbc0) = *(uint *)(iVar6 + 0xbc0) | 0x80;
      *(undefined4 *)(iVar6 + 0xcf0) = 0x30;
      *(undefined4 *)(iVar6 + 0xcf4) = 0x101030;
      puVar7 = *(uint **)(param_1 + 0x234);
      puVar7[0x4c] = 0x60;
      puVar7[0x4d] = 0x101030;
      *puVar7 = *puVar7 | 0x80;
      func_0x80052c6c(10,0xfa,0);
      func_0x80052d10(0x1e,0xfa,0x6e,10);
      func_0x80052c6c(0x28,0x6e,0x28);
      func_0x80052bd0(8,10);
      func_0x80052bd0(3,0x14);
      func_0x80052bd0(2,0x19);
      func_0x80052bd0(3,0x1e);
      func_0x80052bd0(3,0x23);
      func_0x80052bd0(5,0x28);
      func_0x80052bd0(3,0x37);
      func_0x80052bd0(3,0x46);
    }
    _DAT_800e1196 = _DAT_800e1196 + 0x800;
    func_0x8003331c(param_1,param_2,param_3,0);
    _DAT_800e1196 = _DAT_800e1196 + -0x800;
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar5;
    if ((6 < *(byte *)(param_1 + 0x1e9)) && ((*(byte *)(param_1 + 0x1e9) & 3) == 0)) {
      iVar6 = *(int *)(param_1 + 0x234);
      local_20 = 200;
      uVar3 = func_0x80033604();
      local_1e = 0x148 - (uVar3 & 0xff);
      uVar3 = func_0x80033604();
      local_1c = (uVar3 & 0xff) * -2 + 0x100;
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) << 2 | 0x1000,(int)*(short *)(param_1 + 0x66),iVar6 + 0x38,
                      &local_20);
    }
    if ((*(char *)(param_1 + 0x1e9) == 'Y') || (*(char *)(param_1 + 0x1e9) == 'b')) {
      func_0x80077f30(2,0,param_1);
      iVar6 = *(int *)(param_1 + 0x234);
      uVar3 = func_0x80033604();
      local_20 = 0x80 - (uVar3 & 0xff);
      uVar3 = func_0x80033604();
      local_1e = 0x148 - (uVar3 & 0xff);
      uVar3 = func_0x80033604();
      local_1c = 0x80 - (uVar3 & 0xff);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      iVar6 = iVar6 + 0x38;
      func_0x80037780((uVar1 & 0xff) * 4 + 0x1000,(uVar2 & 0xff) << 4,iVar6,&local_20);
      uVar3 = func_0x80033604();
      local_20 = 0x80 - (uVar3 & 0xff);
      uVar3 = func_0x80033604();
      local_1e = 0x148 - (uVar3 & 0xff);
      uVar3 = func_0x80033604();
      local_1c = 0x80 - (uVar3 & 0xff);
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) << 2 | 0x11000,(uVar2 & 0xff) << 4,iVar6,&local_20);
      func_0x80052bd0(3,0);
      func_0x80052c6c(6,0xfa,0);
      if (*(char *)(param_1 + 0x1e9) == 'b') {
        func_0x80052d10(0x3c,0xfa,0,6);
      }
    }
    break;
  case 2:
    *(undefined2 *)(param_1 + 500) = 0x1e;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    sVar4 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar4;
    if (sVar4 == -1) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
  }
  return;
}
