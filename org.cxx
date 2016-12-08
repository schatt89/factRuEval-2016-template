#encoding "utf-8"

OrgDescr -> AnyWord<kwtype="org_descr">;
OrgHead -> AnyWord<kwtype="org_head">;

OrgDescr ->OrgDescr GP;
OrgDescr ->Adj<gnc-agr[1]> OrgDescr<rt, gnc-agr[1]>; // rt- главное слово

GP -> Word<gram="S, gen">; //S - сущ gen-род падеж


Quoted_Words -> AnyWord<l-quoted,r-quoted>;
Quoted_Words -> AnyWord<l-quoted,~r-quoted> Word<~l-quoted,~r-quoted>* AnyWord<~l-quoted,r-quoted>;

Org -> OrgDescr interp(Object.Descr) Word<h-reg1> interp(Object.Name; Object.Type="ORG");
Org -> OrgDescr interp(Object.Descr) Quoted_Words interp(Object.Name; Object.Type="ORG");
Org -> OrgDescr interp(Object.Name; Object.Type="ORG");

Org_noninterp -> OrgHead AnyWord<h-reg1>;


Org -> Org_noninterp interp(Object.Name; Object.Type="ORG");

Root -> Org;