/* FUN_8005db08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005db08  body 0x8005db08..0x8005dc23  size 284 B
 * body sha256 9b5b40b7b45658768b66c9e65947c77abc583df6d378459f1277466b2bce3568
 * provider record sha256 fade6a394b3b494509499b0f5966a34aeec1927b5c3a119a3c4a4df65fbefceb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005db08(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (cVar1 == '\x01') {
    local_18 = 0x8a;
    local_16 = 0x267;
    local_14 = 8;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x30a0e00,0,iVar2,&local_18);
    FUN_80037780(0x1000e00,0,iVar2,&local_18);
    cVar1 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar1 == '\x03') {
    local_18 = 0x15e;
    local_16 = 0x28;
    local_14 = 0xfff1;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x3080900,0,iVar2,&local_18);
    FUN_80037780(0x2000700,(int)((DAT_800e1196 + 0x514) * 0x10000) >> 0x10,iVar2,&local_18);
  }
  return;
}
