/* FUN_8016cb84
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016cb84  body 0x8016cb84..0x8016cec3  size 832 B
 * body sha256 388586e3e377aa2d47f229b351ff5d76e9dc86a91de53b32ee07c3de866bfd76
 * provider record sha256 137a14cea69dda93bd957596d4e1517774e84e53a3f8ead6c293f6687544d841
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016cb84(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  uint *puVar5;
  int iVar6;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  byte local_18 [8];
  
  local_18[0] = 0xd;
  local_18[1] = 0xf;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    bVar4 = local_18[*(byte *)(param_1 + 5)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x800;
    *(uint *)(param_1 + 0x1e8) = (uint)bVar4 * 0x1000000 + 0xf00;
    if ((*(byte *)(param_1 + 5) & 1) != 0) {
      *(undefined2 *)(param_1 + 500) = 0;
    }
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    func_0x80077adc(0x4030001,param_1 + 0x28);
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
    func_0x80052d10(0x21,0x32,0x96,0);
    func_0x80052c6c(8,0xfa,0x21);
    func_0x80052bd0(0x32,0x41);
    func_0x80052c6c(6,0xfa,0x4b);
    func_0x80052c6c(6,0xfa,0x56);
    func_0x80052c6c(6,0xfa,0x73);
    func_0x80052d10(0x5a,0xfa,0,0x79);
  case 1:
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 500);
    func_0x8003331c(param_1,param_2,param_3,0);
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) - *(short *)(param_1 + 500);
    cVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
    if ((*(byte *)(param_1 + 0x1e9) - 0x29 < 0x3a) && ((*(byte *)(param_1 + 0x1e9) & 1) == 0)) {
      iVar6 = *(int *)(param_1 + 0x234);
      local_20 = 0;
      local_1e = 0;
      local_1c = 0;
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) * 8 + 0xbd0,(uVar2 & 0xff) << 4,iVar6 + 0xbf8,&local_20);
    }
    if (*(byte *)(param_1 + 0x1e9) - 100 < 5) {
      iVar6 = *(int *)(param_1 + 0x234);
      local_20 = 0;
      local_1e = 0;
      local_1c = 0;
      uVar1 = func_0x80033604();
      func_0x80037780(0x17d0,(uVar1 & 0xff) << 4,iVar6 + 0xbf8,&local_20);
      iVar6 = *(int *)(param_1 + 0x234);
      local_20 = 0;
      local_1e = 0;
      local_1c = 0;
      uVar1 = func_0x80033604();
      func_0x80037780(0x1bd0,(uVar1 & 0xff) << 4,iVar6 + 0xbf8,&local_20);
      iVar6 = *(int *)(param_1 + 0x234);
      *(uint *)(iVar6 + 0xbc0) = *(uint *)(iVar6 + 0xbc0) | 0x80;
      *(undefined4 *)(iVar6 + 0xcf0) = 0x40;
      *(undefined4 *)(iVar6 + 0xcf4) = 0x202030;
      puVar5 = *(uint **)(param_1 + 0x234);
      puVar5[0x4c] = 0x80;
      puVar5[0x4d] = 0x101030;
      *puVar5 = *puVar5 | 0x80;
    }
    break;
  case 2:
    *(undefined1 *)(param_1 + 6) = 3;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(undefined2 *)(param_1 + 0x1f2) = 0x8000;
    *(char *)(param_1 + 0x1e8) = *(char *)(param_1 + 0x1e8) + '\x01';
  case 3:
    *(undefined1 *)(param_1 + 0x1ea) = 10;
    cVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
    break;
  case 4:
    *(undefined1 *)(param_1 + 6) = 5;
    bVar4 = func_0x80033604();
    *(byte *)(param_1 + 0x207) = (bVar4 & 0x1f) + 3;
  case 5:
    cVar3 = *(char *)(param_1 + 0x207) + -1;
    *(char *)(param_1 + 0x207) = cVar3;
    if (cVar3 == -1) {
      *(undefined1 *)(param_1 + 6) = 3;
    }
    break;
  case 6:
    *(undefined4 *)(param_1 + 4) = 0x7000000;
  }
  return;
}
