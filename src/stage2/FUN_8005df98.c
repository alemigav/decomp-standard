/* FUN_8005df98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005df98  body 0x8005df98..0x8005e0f7  size 352 B
 * body sha256 45cae219d245a1f2416ef40480f04abc8b5a3470b7352a4e32d86b8e7f706770
 * provider record sha256 f6f6463a63b17ff2b005c0eb904544a824869d3864187df2e8545235131e5201
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005df98(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (cVar1 == '\x01') {
    local_18 = 0x82;
    local_16 = 900;
    local_14 = 0xfff6;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x30a1800,0,iVar2,&local_18);
    FUN_80037780(0x1002000,0,iVar2,&local_18);
    local_16 = 0x44c;
    FUN_80037780(0x1023000,0,iVar2,&local_18);
    cVar1 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar1 == '\x04') {
    local_18 = 0x14a;
    local_16 = 0x32;
    local_14 = 0;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x2000900,(int)((DAT_800e1196 + 0x694) * 0x10000) >> 0x10,iVar2,&local_18);
  }
  DAT_800e110c = DAT_800e110c & 0xffffff7f;
  return;
}
